//简单算法
int MaxSum(int n,int* a,int& besti,int& bestj)
{
    int sum=0;
    for(int i=0;i<n;i++)
        for(int j=0;i<n;j++)
    {
        int thisum=0;
        for(int k=i;k<j;k++)
            thisum+=a[k];
        if(thisum>sum)
        {
            sum=thisum;
            besti=i;
            bestj=j;
        }
    }
    return sum;
}


//优化算法

int MaxSumadvance(int n,int* a,int& besti,int& bestj)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
       int thisum=0;
       for(int k=i;k<n;k++)
       {
        thisum+=a[k];
        if(thisum>sum)
        {
            sum=thisum;
            besti=i;
            bestj=j;
        }
       }
    }
    return sum;
}


//分治算法
int MaxSubSum(int*a,int left,int right)
{

    int sum=0;
    if(left==right) sum=a[left]>0?a[left]:0;
    else
    {
        int center=(left+right)/2;
        int leftsum=MaxSubSum(a,left,center);
        int rightsum=MaxSubSum(a,center+1,right);
        int s1=0;
        itn lefts=0;
        for(int i=center;i>=left;i--)
        {

            lefts+=a[i];
            if(lefts>s1)
                s1=lefts;
        }

        int s2=0;
        int rights=0;
        for(int i=center+1;i<=right;i++)
        {
            right+=a[i];
            if(right>s2)
                s2=rights;

        }
        sum=s1+s2;
        if(sum<leftsum) sum=leftsum;
        if(sum<rightsum) sum=rightsum;
    }
    return sum;
}

int MaxSum2(int n,int* a)
{

    return MaxSubSum(a,1,n);
}




//动态规划算法
int MaxSum3(int n,int* a)
{
    int sum=0;
    b=0;
    for(int i=0;i<n;i++)
    {
        if(b>0) b+=a[i];
      else
        b=a[i];
      if(b>sum)
        sum=b;
    }
        return sum;
}

//矩阵的动态规划算法
int MaxSum2D(int m,int n,int** a)
{
    int sum=0;
    int *b=new int[n+1];
    for(int i=0;i<m;i++)
    {
        for(int k=0;k<n;k++)
            b[k]=a[i][k];

        for(int j=i+1;j<m;j++)
        {
            for(int k=0;k<n;k++)
                b[k]+=a[j][k];
            int maxx=MaxSum3(n,b);
            if(maxx>sum)  sum=maxx;
        }
    }
    delete[] b;
    return sum;
}


//最大m子段和问题的动态规划算法

int MaxSum4(int m,int n,int *a)
{

    if(n<m||m<1)
        return 0;
    int **b=new int* [m+1];
    for(int i=0;i<=m;i++)
        b[i]=new int[n+1];

    for(int i=0;i<m;i++)
        b[i][0]=0;
    for(int j=1;j<n;j++)
        b[0][j]=0;
    for(int i=0;i<m;i++)
        for(int j=i;j<=n-m+i;j++)
    if(j>i)
    {
        b[i][j]=b[i][j-1]+a[j];
        for(int k=i-1;k<j;k++)
            if(b[i][j]<b[i-1][k]+a[j])
            b[i][j]=b[i-1][k]+a[j];
    }
    else
        b[i][j]=b[i-1][j-1]+a[j];
    int sum=0;
    for(int j=m;j<=n;j++)
        if(sum<b[m][j])
            sum=b[m][j];
    return sum;
}


//上述的改进算法

int MaxSum5(int m,int n,int* a)
{
    if(n<m||m<l)
        return 0;
    int* b=new int[n+1];
    int* c=new int[n+1];
    b[0]=0;
    c[1]=0;

    for(int i=1;i<=m;i++)

}










