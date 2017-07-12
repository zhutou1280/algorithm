
#include"CirList.cpp"

int main()
{

    CirList<double> s;
    s.print();

    for(int i=0;i<10;i++)
        s.AddTail(i*1.1);
    s.print();

    s.RemoveThis();
    s.print();

    s.SetBegin();
    s.GetNext();
    s.print();
    ListNode<double>* a=s.GetCur();
    cout<<a->GetData()<<endl;
    cout<<s.IsEmpty()<<endl;
    cout<<"count:  "<<s.GetCount()<<endl;
    s.RemoveAll();

    s.print();
    return 0;
}