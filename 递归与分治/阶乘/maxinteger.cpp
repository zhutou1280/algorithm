


int qq(int n,int m)
{
    if(n<1||m<1)
        return 0;
    if((n==1)||(m==1))
     return 1;
    if(n<m)
    return qq(n,n);
    if(n==m)
      return 1+qq(n,n-1);

    return qq(n-m,m)+qq(n,m-1);
}


