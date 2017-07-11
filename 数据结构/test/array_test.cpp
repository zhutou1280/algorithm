#include "Array.cpp"
#include<iostream>


using namespace std;

//test array.h



int main()
{
    Array<int> a(20);
    for(int i=0;i<20;i++)
        a[i]=i;
    for(int i=0;i<20;i++)
        cout<<a[i]<<endl;



    cout<<"第二次测试"<<endl;
    Array<int> b;
    for(int i=0;i<DefaultSize;i++)
      {

       b[i]=i;
        cout<<b[i]<<"\t";
      }
      cout<<endl;

    cout<<"第三个测试"<<endl;
    Array<int> c(b);
    for(int i=0;i<DefaultSize;i++)
       cout<<c[i]<<"\t";

    cout<<"第四个测试"<<endl;
    Array<int> d;
    d=a;
    for(int i=0;i<10;i++)
      cout<<d[i]<<"\t";

    cout<<"第5个测试"<<endl;
    cout<<a.length()<<"\t"<<b.length()<<"\t"<<c.length()<<"\t"<<d.length()<<"\t";
    b.Resize(10);
    cout<<b.length();
    return 0;

}
