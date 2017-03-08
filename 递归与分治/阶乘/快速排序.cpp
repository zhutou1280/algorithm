
template<class T>
void Swap(T&a,T&b)
{
    a=a+b;
    b=a-b;
    a=a-b;
}

template<class  T>
void partion(T a[],int p,int r)
{
 int i=p;
 int j=r+1;
 T x=a[p];
 while(true)
 {
     while(a[++i]<x);
     while(a[--j]>x);
     if(i>=j)
        break;
     Swap(a[i],a[j]);
 }
 a[p]=a[j];
 a[j]=x;
 return j;
}



template<class T>
void  Quicksort(T a[],int p,int r)
{
 if(p<r)
 {
    int q=partion(a,p,r);
    Quicksort(a,p,q-1);
    Quicksort(a,q+1,r);
 }
}
