#include<iostream>
template<class T>
void Swap(T& a,T& b)
{
    T c=a;
    a=b;
    b=c;
}


template<class T>
void permatution(T a[],int start,int end)
{
    if(start>end)
      {
          for(int i=0; i<=end; i++)
            std::cout<<a[i];
    std::cout<<std::endl;
      }
else
        for(int i=start; i<=end; i++)
        {

            Swap(a[start],a[i]);
            permatution(a,start+1,end);
            Swap(a[i],a[start]);

        }
}
