//棋盘问题
//该问题在于打印所有的填充方式，对于2的k次方的棋盘，中有一个黑点，覆盖整个棋盘。

#include<iostream>

using namespace std;

const int maxn=64;
int board[maxn][maxn];
int tile=0;
void fillchess(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)
        return ;
    int t=tile++;
    int s=size/2;
if(dr<s-1+tr&&dc<s-1+tc)
    fillchess(tr,tc,dr,dc,s);
else
{
    board[tr+s-1][tc+s-1]=t;
    fillboard(tr,tc,tr+s-1,tc+s-1,s);
}

if(dr<s-1+tr&&dc>=s-1+tc)
    fillchess(tr,tc+s,dr,dc,s);
else
    {
        board[tr+s-1][tc+s]=t;
        fillchess(tr,tc+s,tr+s-1,tc+s,s);
    }

    if(dr>=s-1+tr&&dc<tc+s-1)
        fillchess(tr+s,tc,dr,dc,s);
    else
    {
        board[tr+s][tc+s-1]=t;
        fillchess(tr+s,tc,tr+s,tc+s-1,s);
    }

    if(dr>=s-1+tr&&dc>=s-1+tc)
        fillchess(dr+s,dc+s,dr,dc,s);
    else
    {
        board[tr+s][tc+s]=t;
        fillchess(tr+s,tc+s,tr+s,tc+s,s);
    }
}

