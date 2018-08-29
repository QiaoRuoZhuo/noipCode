/*
	Name: 棋盘覆盖问题
	Copyright: 
	Author: 
	Date: 10-01-18 22:28
	Description:
棋盘覆盖问题要求在2^k * 2^k 个方格组成的棋盘中，你给定任意一个特殊点，用一种方案实现对除该特殊点的棋盘实现全覆盖。 
解决方案就是利用分治法，将方形棋盘分成4部分，如果该特殊点在某一部分，我们就去递归他，
如果不在某一部分，我们假设一个点为特殊点，同样递归下去，直到全覆盖。
每层递归都要遍历4个子方块，同层子方块的3个“假特殊方格”使用相同颜色的色块覆盖，恰好构成一个L型骨牌 。 
左上角的子棋盘（若不存在特殊方格）：则将该子棋盘右下角的那个方格假设为特殊方格；
右上角的子棋盘（若不存在特殊方格）：则将该子棋盘左下角的那个方格假设为特殊方格；
左下角的子棋盘（若不存在特殊方格）：则将该子棋盘右上角的那个方格假设为特殊方格；
右下角的子棋盘（若不存在特殊方格）：则将该子棋盘左上角的那个方格假设为特殊方格；
*/
#include<iostream>  
using namespace std;  
  
const int MAX = 8;  
int tile = 1;  
int board[MAX][MAX] = {0};  
  
void ChessBoard(int tr, int tc, int dr, int dc, int size)  
{  
    if (size == 1)  
        return;  
  
    int t = tile++;   //L型骨牌号（颜色） 
    int sz = size / 2; //分割棋盘
  
    if (dr < tr+sz && dc < tc+sz)//特殊方格在左上角子棋盘  
    {
		ChessBoard(tr, tc, dr, dc, sz);  
	}
    else //否则标记一个假设的特殊点，递归该部分  
	{  
        board[tr+sz-1][tc+sz-1] = t;  
        ChessBoard(tr, tc, tr+sz-1, tc+sz-1, sz);  
    }  
  
    if (dr < tr+sz && dc >= tc+sz) //特殊方格在右上角子棋盘  
    {
		ChessBoard(tr, tc+sz, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz-1][tc+sz] = t;  
        ChessBoard(tr, tc+sz, tr+sz-1, tc+sz, sz);  
    }  
  
    if (dr >= tr+sz && dc < tc+sz)  //特殊方格在左下角子棋盘  
    {
		ChessBoard(tr+sz, tc, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz][tc+sz-1] = t;  
        ChessBoard(tr+sz, tc, tr+sz, tc+sz-1, sz);  
    }  
  
    if (dr >= tr+sz && dc >= tc+sz) //特殊方格在右下角子棋盘  
    {
		ChessBoard(tr+sz, tc+sz, dr, dc, sz);  
	}
    else
	{  
        board[tr+sz][tc+sz] = t;                       
        ChessBoard(tr+sz, tc+sz, tr+sz, tc+sz, sz);     
    }  
}  
  
void PrintChessBoard()  
{  
    cout.setf(ios::left);     //左对齐  
    for (int i=0; i<MAX; ++i)
	{  
        for (int j=0; j<MAX; ++j)
		{  
            cout.width(3);    //打印宽度为3  
            cout << board[i][j];  
        }  
        cout << endl;  
    }  
}  
  
int main()  
{  
    ChessBoard(0, 0,0, 1, MAX);  
    PrintChessBoard();  
    return 0;  
}  
