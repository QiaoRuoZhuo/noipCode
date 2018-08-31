/*
  Name: 数组基本操作 
  Copyright: 
  Author: 
  Date: 11-04-17 13:53
  Description: 
*/

//////////////////第1节（基本操作） 
//输出数组A的所有元素（元素间用空格隔开）
void PrintArray(const int A[], int n);
//输出数组A中区域[low,high]的元素（元素间用空格隔开）
void PrintArray(const int A[], int low, int high);
//将数组A中区域[low,high]的元素复制到数组B，并返回数组B的长度 
int CopyArray(const int A[], int B[], int low, int high);
//生成n个随机数为数组A赋值 
void CreateArray(int A[], int n);
//从键盘读入n个数为数组A赋值 
void CreateArray(int A[], int n);
//将数组A中值为x的元素改为y 
void ChangeValue(int A[], int n, int x, int y);
//统计数组A中奇数的数量 
int OddNumber(const int A[], int n);
//将数组A中的奇数存储到数组B，并返回数组B的长度 
int OddNumerArray(const int A[], int B[], int n);
//在数组A中查询是否存在值为x的元素，若存在返回第一个值为x的元素的下标，否则返回-1 
int Find(const int A[], int n, int x);
//统计数组A中值为x的元素的数量 
int NumOfValue(const int A[], int n, int x);

//////////////////////第2节（选择排序） 
//返回数组A中的最小值
int MinValue(const int A[], int n);
//返回数组A中区域[low,high]的最小值的下标
int MinValue(const int A[], int low, int high);
//交换数组A中下标分别为i和j的元素的值 
void Swap(int A[], int i, int j);
//用选择排序法对数组A进行排序（非递减序列） 
void SelectionSort(int A[], int n);
/*此为本节课重点，分为3个步骤：用选择排序的方法对某组同学进行排高矮游戏；
 示例：对3，6，2，1，4，5进行排序，并列出每轮选择后的数组序列；
 编写代码，并对各个变量和语句进行注释说明 
课后作业为选择排序法的应用：1.给出一个未排序序列，要求列出每轮选择后的数组序列；
2.给出一个班级的考试成绩，要求输出平均分，最高分和最低分，还有中位数和前10名的成绩（注意名次并列的情况） 
 */ 
//////////////////////第3节（插入排序） 
//复习:生成n个随机数为数组A赋值，输出数组A的所有元素（元素间用空格隔开）
//删除数组A的最后一个元素，并返回新数组的长度
int Delete(int A[], int n);
//删除数组A的第一个元素，并返回新数组的长度
int Delete(int A[], int n);
//删除数组A中下标为pos的元素，并返回新数组的长度
int Delete(int A[], int n, int pos);
//删除数组中所有值为x的元素，并返回新数组的长度
int DeleteX(int A[], int n, int x);
//在数组A尾部插入一个值为x的元素，并返回新数组的长度 
int Insert(int A[], int n, int x);
//在数组A首部插入一个值为x的元素，并返回新数组的长度 
int Insert(int A[], int n, int x);
//在数组A下标为pos处插入一个值为x的元素，并返回新数组的长度 
int Insert(int A[], int n, int pos, int x); 
//用插入排序法对数组A进行排序（非递减序列） 
void InsertSort(int A[], int n);
/*此为本节课重点，分为3个步骤：用插入排序的方法对扑克牌进行排序；
 示例：对3，6，2，1，4，5进行排序，并列出每轮插入后的数组序列；
 编写代码，并对各个变量和语句进行注释说明 
课后作业为插入排序法的应用：1.给出一个未排序序列，要求列出每轮插入后的数组序列；
2.构造一个长为n的随机数组，用插入法进行排序，删除重复元素后返回新数组的长度。 
 */ 
//////////////////////第4节（冒泡排序） 学习如何优化程序 
//复习选择排序法，并给出一个优化算法
//选择排序改进算法：同时选出最大和最小值
void SelectionSort_2(int vec[], int n);
//冒泡法基础程序：将较大数向上移动
void BubbleSort_1(int lib[], int n);
 //改进版1：设置交换标志，以便提前结束扫描
void BubbleSort_2(int lib[], int n);
//改进版2：缩小内层循环的扫描范围
void BubbleSort_3(int lib[], int n);
//改进版3：双向冒泡
void BubbleSort_4(int lib[], int n);
/*课后作业为复习三种排序算法，给出一个实例，分别使用3种排序算法进行排序，
并写出每轮排序操作的次数和生成的数组序列；
2.找到一个排序算法的应用，请学生选择自己最拿手的方法进行排序。 
 */ 


//////////////////////第5节（其他常见算法） 
//将数组进行逆序处理（分别采用交换算法和高效的移出空位算法 
void InvertedArray(int A[], int n);
//移动数组（整体交换左右区域）
void MoveArray(int A[], int low, int mid, int high);
//合并有序数组（为今后的合并排序法打基础）
int MergeArray(const int A[], const int B[], int C[], int lenA, int lenB); 
