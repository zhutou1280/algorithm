#include"Array.h"


template<class Type>
Array<Type>& Array<Type>::operator= (const Array<Type>& rhs)
{
    int n=rhs.ArraySize;
    if(ArraySize!=n)
    {
        delete[] elements;
        elements=new Type[n];
        if(elements ==NULL)
        {
            ArraySize=0;
            cerr<<"分配内存出错:error for wrong allocating memory"<<endl;
            exit(1);
        }
        ArraySize=n;
    }

    Type* destptr=elements;
    Type* srcptr=rhs.elements;
    while(n--)
        *destptr++=*srcptr++;
    return *this;
}


template<class Type>
Array<Type>::Array(int Size)
{
    if(Size<=0)
       {
           ArraySize=0;
           cerr<<"数组大小非法,error:wrong arraysize"<<endl;
           return;
       }
    elements= new Type[Size];
    if(elements==NULL)
     {
         ArraySize=0;
         cerr<<"存储分配错误，error,allocating room wrong!"<<endl;
         exit(1);
     }
     ArraySize=Size;
}


template<class Type>
Array<Type>::Array(const Array<Type>& x)
{
    int n=x.ArraySize;
    ArraySize=n;
    elements=new Type[n];
    if(elements==NULL)
      {
          ArraySize=0;
          cerr<<"存储分配错误,error:wrong allocating memeroy"<<endl;
          exit(1);
      }
      Type* srcptr=x.elements;
      Type* desptr=elements;
      while(n--)
        *desptr++=*srcptr++;
}


template<class Type>
Type& Array<Type>::operator[](int i)
{
    if(i<0||i>ArraySize-1)
     {
         cerr<<"数组下标越界:error,beyond the array range!"<<endl;
         exit(1);
     }
     return elements[i];
}

template<class Type>
void Array<Type>::Resize(int sz)
{
    if(sz>=0&&sz!=ArraySize)
    {
        Type* newarray=new Type[sz];

        if(newarray==NULL)
        {
            cerr<<"存储分配错:error,wrong allocating memory!"<<endl;
            return;
        }
        int n=(sz<=ArraySize)?sz:ArraySize;

        Type* srcptr=elements;
        Type* desptr=newarray;
        while(n--)
            *desptr++=*srcptr++;
            delete [] elements;
            elements=newarray;
            ArraySize=sz;
    }

}




















