#include<string>
#include"DouList.cpp"

int main()
{

    DouList<char> a;
    string s("hellobaby");
    for(size_t i=0;i<s.length();i++)
        a.AddTail(s[i]);
    a.print();

    a.BackCur();
    a.RemoveThis(0);
    a.print();

    a.BackCur();
    a.InsertAfter('z');
    a.print();

    a.TowardCur();
    a.RemoveThis(0);
    cout<<"a is empty"<<a.IsEmpty()<<"\ta count"<<a.GetCount()<<endl;

    a.AddHead('x');
    a.print();

    a.SetBegin();
    a.GetNext();
    DouListNode<char>* xx=a.GetCur();
    cout<<xx->GetData()<<"\t"<<a.GetTail()->GetData()<<endl;

    cout<<a.GetNext()<<"\t"<<a.GetPrior()<<endl;
    a.RemoveAll();
    a.print();

    return 0;
}
