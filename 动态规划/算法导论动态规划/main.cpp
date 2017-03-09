#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;


int CUT_ROD(int* p,int n)
{
    if(n==0) return 0;
    int q=0;
    for(int i=0; i<n; i++)
        q=max(q,p[i]+CUT_ROD(p,n-i-1));
    return q;
}


int MEMOIZED_COt_ROD_AUX(int*p,int n,int* r)
{
    if(r[n]>=0)
        return r[n];
    int q;
    if(n==0)  q=0;
    else
    {
        q=-10000;
        for(int i=0; i<n; i++)
            q=max(q,p[i]+MEMOIZED_COt_ROD_AUX(p,n-i-1,r));
    }
    r[n]=q;

    return q;
}

//自顶向下的方法
int MEMOIZED_COt_ROD(int* p,int n)
{
    int* r=new int[n+1];
     for(int i=0;i<=n;i++)
        *(r+i)=-100;
    int x=MEMOIZED_COt_ROD_AUX(p,n,r);
    delete[] r;
    return x;
}


int BOTTOM_UP_CUT_ROD(int* p,int n)
{
    int* r=new int[n+1];
    r[0]=0;
    for(int i=0;i<n;i++)
    {
        int q=-100;
        for(int j=0;j<=i;j++)
           q=max(q,p[i]+r[i-j]);
        r[i]=q;
    }
    int x=r[n-1];
    delete[] r;
    return x;
}

int main()
{
    int p[10]= {1,5,8,9,10,17,17,20,24,30};

    int s=BOTTOM_UP_CUT_ROD(p,9);
    cout<<s<<endl;
    return 0;
}
