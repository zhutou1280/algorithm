#include<iostream>
using namespace std;


void matrix(int* p,int n,int** m,int** s)
{
      for(int i=0;i<n;i++)
         m[i][i]=0;

      for(int r=2;r<=n;r++)
       for(int i=0;i<=n-r;i++)
       {
           int j=i+r-1;
           m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
           s[i][j]=i;
           for(int k=i+1;k<j;k++)
           {
               int t=m[i][k-1]+m[k][j]+p[i-1]*p[k]*p[j];
               if(t<m[i][j])
               {
                   m[i][j]=t;
                   s[i][j]=k;
               }
           }
       }
}


void traceback(int i,int j,int** s)
  {

      if(i==j)
      return ;
      traceback(i,s[i][j],s);
      traceback(s[i][j]+1,j,s);
      cout<<"Multiply A "<<i<<","<<s[i][j];
      cout<<" and A "<<(s[i][j]+1)<<","<<j<<endl;
  }





//recurisive version

int RecurMatrix(int i,int j)
{
    if(i==j) return 0;
    int u=RecurMatrix(i,i)+RecurMatrix(i+1,j)+p[i-1]*p[i]*[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=RecurMatrix(i,k)+RecurMatrix(k+1,j)+p[i-1]*[k]*p[j];
        if(t<u)
        {
            u=t;
            s[i][j]=k;
        }
    }
    return
    u;
}


//±¸ÍüÂ¼·½·¨

int MemoizedMatrix(int n,int** m,int**s)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        m[i][j]=0;
    return Lookup(1,n)
}


int Lookup(int i,int j)
{
    if(m[i][j]>0)
        return m[i][j];
    if(i==j)
        return 0;
    int u=Lookup(i,i)+Lookup(i+1,j)+p[i-1]*p[i]*p[j];
    s[i][j]=i;
    for(int k=i+1;k<j;k++)
    {
        int t=Lookup(i,k)+Lookup(k+1,j)+p[i-1]*p[k]*p[j];
        if(t<u)
        {
            u=t;
            s[i][j]=k;
        }
    }
        m[i][j]=u;
        return u;
}

















