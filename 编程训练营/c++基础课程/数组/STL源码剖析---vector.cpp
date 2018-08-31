/*
  Name: STL源码剖析---vector
  Copyright: 
  Author: 
  Date: 15-03-17 14:18
  Description: 
*/
#include<iostream>  
#include<memory.h>  
  
using namespace std;  
  
// alloc是SGI STL的空间配置器  
template <class T, class Alloc = alloc>  
class vector  
{  
public:  
    // vector的嵌套类型定义,typedefs用于提供iterator_traits<I>支持  
    typedef T value_type;  
    typedef value_type* pointer;  
    typedef value_type* iterator;  
    typedef value_type& reference;  
    typedef size_t size_type;  
    typedef ptrdiff_t difference_type;  
protected:  
    // 这个提供STL标准的allocator接口  
    typedef simple_alloc <value_type, Alloc> data_allocator;  
  
    iterator start;               // 表示目前使用空间的头  
    iterator finish;              // 表示目前使用空间的尾  
    iterator end_of_storage;      // 表示实际分配内存空间的尾  
  
    void insert_aux(iterator position, const T& x);  
  
    // 释放分配的内存空间  
    void deallocate()  
    {  
        // 由于使用的是data_allocator进行内存空间的分配,  
        // 所以需要同样使用data_allocator::deallocate()进行释放  
        // 如果直接释放, 对于data_allocator内部使用内存池的版本  
        // 就会发生错误  
        if (start)  
            data_allocator::deallocate(start, end_of_storage - start);  
    }  
  
    void fill_initialize(size_type n, const T& value)  
    {  
        start = allocate_and_fill(n, value);  
        finish = start + n;                         // 设置当前使用内存空间的结束点  
        // 构造阶段, 此实作不多分配内存,  
        // 所以要设置内存空间结束点和, 已经使用的内存空间结束点相同  
        end_of_storage = finish;  
    }  
  
public:  
    // 获取几种迭代器  
    iterator begin() { return start; }  
    iterator end() { return finish; }  
  
    // 返回当前对象个数  
    size_type size() const { return size_type(end() - begin()); }  
    size_type max_size() const { return size_type(-1) / sizeof(T); }  
    // 返回重新分配内存前最多能存储的对象个数  
    size_type capacity() const { return size_type(end_of_storage - begin()); }  
    bool empty() const { return begin() == end(); }  
    reference operator[](size_type n) { return *(begin() + n); }  
  
    // 本实作中默认构造出的vector不分配内存空间  
    vector() : start(0), finish(0), end_of_storage(0) {}  
  
  
    vector(size_type n, const T& value) { fill_initialize(n, value); }  
    vector(int n, const T& value) { fill_initialize(n, value); }  
    vector(long n, const T& value) { fill_initialize(n, value); }  
  
    // 需要对象提供默认构造函数  
    explicit vector(size_type n) { fill_initialize(n, T()); }  
  
    vector(const vector<T, Alloc>& x)  
    {  
        start = allocate_and_copy(x.end() - x.begin(), x.begin(), x.end());  
        finish = start + (x.end() - x.begin());  
        end_of_storage = finish;  
    }  
  
    ~vector()  
    {  
        // 析构对象  
        destroy(start, finish);  
        // 释放内存  
        deallocate();  
    }  
  
    vector<T, Alloc>& operator=(const vector<T, Alloc>& x);  
  
    // 提供访问函数  
    reference front() { return *begin(); }  
    reference back() { return *(end() - 1); }  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // 向容器尾追加一个元素, 可能导致内存重新分配  
    ////////////////////////////////////////////////////////////////////////////////  
    //                          push_back(const T& x)  
    //                                   |  
    //                                   |---------------- 容量已满?  
    //                                   |  
    //               ----------------------------  
    //           No  |                          |  Yes  
    //               |                          |  
    //               ↓                          ↓  
    //      construct(finish, x);       insert_aux(end(), x);  
    //      ++finish;                           |  
    //                                          |------ 内存不足, 重新分配  
    //                                          |       大小为原来的2倍  
    //      new_finish = data_allocator::allocate(len);       <stl_alloc.h>  
    //      uninitialized_copy(start, position, new_start);   <stl_uninitialized.h>  
    //      construct(new_finish, x);                         <stl_construct.h>  
    //      ++new_finish;  
    //      uninitialized_copy(position, finish, new_finish); <stl_uninitialized.h>  
    ////////////////////////////////////////////////////////////////////////////////  
  
    void push_back(const T& x)  
    {  
        // 内存满足条件则直接追加元素, 否则需要重新分配内存空间  
        if (finish != end_of_storage)  
        {  
            construct(finish, x);  
            ++finish;  
        }  
        else  
            insert_aux(end(), x);  
    }  
  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // 在指定位置插入元素  
    ////////////////////////////////////////////////////////////////////////////////  
    //                   insert(iterator position, const T& x)  
    //                                   |  
    //                                   |------------ 容量是否足够 && 是否是end()?  
    //                                   |  
    //               -------------------------------------------  
    //            No |                                         | Yes  
    //               |                                         |  
    //               ↓                                         ↓  
    //    insert_aux(position, x);                  construct(finish, x);  
    //               |                              ++finish;  
    //               |-------- 容量是否够用?  
    //               |  
    //        --------------------------------------------------  
    //    Yes |                                                | No  
    //        |                                                |  
    //        ↓                                                |  
    // construct(finish, *(finish - 1));                       |  
    // ++finish;                                               |  
    // T x_copy = x;                                           |  
    // copy_backward(position, finish - 2, finish - 1);        |  
    // *position = x_copy;                                     |  
    //                                                         ↓  
    // data_allocator::allocate(len);                       <stl_alloc.h>  
    // uninitialized_copy(start, position, new_start);      <stl_uninitialized.h>  
    // construct(new_finish, x);                            <stl_construct.h>  
    // ++new_finish;  
    // uninitialized_copy(position, finish, new_finish);    <stl_uninitialized.h>  
    // destroy(begin(), end());                             <stl_construct.h>  
    // deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    iterator insert(iterator position, const T& x)  
    {  
        size_type n = position - begin();  
        if (finish != end_of_storage && position != end())  
        {  
            construct(finish, x);  
            ++finish;  
        }  
        else  
            insert_aux(position, x);  
        return begin() + n;  
    }  
  
    iterator insert(iterator position) { return insert(position, T()); }  
  
    void pop_back()  
    {  
        --finish;  
        destroy(finish);  
    }  
  
    iterator erase(iterator position)  
    {  
        if (position + 1 != end())  
            copy(position + 1, finish, position);  
        --finish;  
        destroy(finish);  
        return position;  
    }  
  
  
    iterator erase(iterator first, iterator last)  
    {  
        iterator i = copy(last, finish, first);  
        // 析构掉需要析构的元素  
        destroy(i, finish);  
        finish = finish - (last - first);  
        return first;  
    }  
  
    // 调整size, 但是并不会重新分配内存空间  
    void resize(size_type new_size, const T& x)  
    {  
        if (new_size < size())  
            erase(begin() + new_size, end());  
        else  
            insert(end(), new_size - size(), x);  
    }  
    void resize(size_type new_size) { resize(new_size, T()); }  
  
    void clear() { erase(begin(), end()); }  
  
protected:  
    // 分配空间, 并且复制对象到分配的空间处  
    iterator allocate_and_fill(size_type n, const T& x)  
    {  
        iterator result = data_allocator::allocate(n);  
        uninitialized_fill_n(result, n, x);  
        return result;  
    }  
  
    // 提供插入操作  
    ////////////////////////////////////////////////////////////////////////////////  
    //                 insert_aux(iterator position, const T& x)  
    //                                   |  
    //                                   |---------------- 容量是否足够?  
    //                                   ↓  
    //              -----------------------------------------  
    //        Yes   |                                       | No  
    //              |                                       |  
    //              ↓                                       |  
    // 从opsition开始, 整体向后移动一个位置                     |  
    // construct(finish, *(finish - 1));                    |  
    // ++finish;                                            |  
    // T x_copy = x;                                        |  
    // copy_backward(position, finish - 2, finish - 1);     |  
    // *position = x_copy;                                  |  
    //                                                      ↓  
    //                            data_allocator::allocate(len);  
    //                            uninitialized_copy(start, position, new_start);  
    //                            construct(new_finish, x);  
    //                            ++new_finish;  
    //                            uninitialized_copy(position, finish, new_finish);  
    //                            destroy(begin(), end());  
    //                            deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    template <class T, class Alloc>  
    void insert_aux(iterator position, const T& x)  
    {  
        if (finish != end_of_storage)    // 还有备用空间  
        {  
            // 在备用空间起始处构造一个元素，并以vector最后一个元素值为其初值  
            construct(finish, *(finish - 1));  
            ++finish;  
            T x_copy = x;  
            copy_backward(position, finish - 2, finish - 1);  
            *position = x_copy;  
        }  
        else   // 已无备用空间  
        {  
            const size_type old_size = size();  
            const size_type len = old_size != 0 ? 2 * old_size : 1;  
            // 以上配置元素：如果大小为0，则配置1（个元素大小）  
            // 如果大小不为0，则配置原来大小的两倍  
            // 前半段用来放置原数据，后半段准备用来放置新数据  
  
            iterator new_start = data_allocator::allocate(len);  // 实际配置  
            iterator new_finish = new_start;  
            // 将内存重新配置  
            try  
            {  
                // 将原vector的安插点以前的内容拷贝到新vector  
                new_finish = uninitialized_copy(start, position, new_start);  
                // 为新元素设定初值 x  
                construct(new_finish, x);  
                // 调整水位  
                ++new_finish;  
                // 将安插点以后的原内容也拷贝过来  
                new_finish = uninitialized_copy(position, finish, new_finish);  
            }  
            catch(...)  
            {  
                // 回滚操作  
                destroy(new_start, new_finish);  
                data_allocator::deallocate(new_start, len);  
                throw;  
            }  
            // 析构并释放原vector  
            destroy(begin(), end());  
            deallocate();  
  
            // 调整迭代器，指向新vector  
            start = new_start;  
            finish = new_finish;  
            end_of_storage = new_start + len;  
        }  
    }  
  
    ////////////////////////////////////////////////////////////////////////////////  
    // 在指定位置插入n个元素  
    ////////////////////////////////////////////////////////////////////////////////  
    //             insert(iterator position, size_type n, const T& x)  
    //                                   |  
    //                                   |---------------- 插入元素个数是否为0?  
    //                                   ↓  
    //              -----------------------------------------  
    //        No    |                                       | Yes  
    //              |                                       |  
    //              |                                       ↓  
    //              |                                    return;  
    //              |----------- 内存是否足够?  
    //              |  
    //      -------------------------------------------------  
    //  Yes |                                               | No  
    //      |                                               |  
    //      |------ (finish - position) > n?                |  
    //      |       分别调整指针                              |  
    //      ↓                                               |  
    //    ----------------------------                      |  
    // No |                          | Yes                  |  
    //    |                          |                      |  
    //    ↓                          ↓                      |  
    // 插入操作, 调整指针           插入操作, 调整指针           |  
    //                                                      ↓  
    //            data_allocator::allocate(len);  
    //            new_finish = uninitialized_copy(start, position, new_start);  
    //            new_finish = uninitialized_fill_n(new_finish, n, x);  
    //            new_finish = uninitialized_copy(position, finish, new_finish);  
    //            destroy(start, finish);  
    //            deallocate();  
    ////////////////////////////////////////////////////////////////////////////////  
  
    template <class T, class Alloc>  
    void insert(iterator position, size_type n, const T& x)  
    {  
        // 如果n为0则不进行任何操作  
        if (n != 0)  
        {  
            if (size_type(end_of_storage - finish) >= n)  
            {      // 剩下的备用空间大于等于“新增元素的个数”  
                T x_copy = x;  
                // 以下计算插入点之后的现有元素个数  
                const size_type elems_after = finish - position;  
                iterator old_finish = finish;  
                if (elems_after > n)  
                {  
                    // 插入点之后的现有元素个数 大于 新增元素个数  
                    uninitialized_copy(finish - n, finish, finish);  
                    finish += n;    // 将vector 尾端标记后移  
                    copy_backward(position, old_finish - n, old_finish);  
                    fill(position, position + n, x_copy); // 从插入点开始填入新值  
                }  
                else  
                {  
                    // 插入点之后的现有元素个数 小于等于 新增元素个数  
                    uninitialized_fill_n(finish, n - elems_after, x_copy);  
                    finish += n - elems_after;  
                    uninitialized_copy(position, old_finish, finish);  
                    finish += elems_after;  
                    fill(position, old_finish, x_copy);  
                }  
            }  
            else  
            {   // 剩下的备用空间小于“新增元素个数”（那就必须配置额外的内存）  
                // 首先决定新长度：就长度的两倍 ， 或旧长度+新增元素个数  
                const size_type old_size = size();  
                const size_type len = old_size + max(old_size, n);  
                // 以下配置新的vector空间  
                iterator new_start = data_allocator::allocate(len);  
                iterator new_finish = new_start;  
                __STL_TRY  
                {  
                    // 以下首先将旧的vector的插入点之前的元素复制到新空间  
                    new_finish = uninitialized_copy(start, position, new_start);  
                    // 以下再将新增元素（初值皆为n）填入新空间  
                    new_finish = uninitialized_fill_n(new_finish, n, x);  
                    // 以下再将旧vector的插入点之后的元素复制到新空间  
                    new_finish = uninitialized_copy(position, finish, new_finish);  
                }  
#         ifdef  __STL_USE_EXCEPTIONS  
                catch(...)  
                {  
                    destroy(new_start, new_finish);  
                    data_allocator::deallocate(new_start, len);  
                    throw;  
                }  
#         endif /* __STL_USE_EXCEPTIONS */  
                destroy(start, finish);  
                deallocate();  
                start = new_start;  
                finish = new_finish;  
                end_of_storage = new_start + len;  
            }  
        }  
    }  
};  
