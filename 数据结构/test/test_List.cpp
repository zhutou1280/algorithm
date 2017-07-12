
#include"List.cpp"

int main()
{
    List<int>  a;
    for(int i=0;i<10;i++)
        a.AddTail(i);

    a.print();

   a.RemoveTail();
   a.print();

   a.InsertAt(1,100);
   a.print();

   a.RemoveAt(1);
   a.print();


   int x=a.GetAt(1);
   cout<<x<<" "<<a.Isempty()<<endl;

   int xx=a.GetCount();
   cout<<xx<<endl;

   ListNode<int>* w,*z,*y;
   w=a.GetHead();
   cout<<w->GetData()<<endl;
   z=a.GetTail();
   cout<<z->GetData()<<endl;
   y=a.GetNodeAt(2);
   cout<<y->GetData()<<endl;

   a.RemoveAll();
   a.print();
   return 0;
}
