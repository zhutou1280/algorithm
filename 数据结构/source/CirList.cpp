#include"CirList.h"

#include<iostream>
using namespace std;

template<class T>
CirList<T>::CirList()
{
    head=tail=new ListNode<T>;
    cur=head;
    head->SetLink(head);
}

template<class T>
CirList<T>::~CirList()
{
    RemoveAll();
    delete head;
}

template<class T>
bool CirList<T>::AddTail(T value)
{
    ListNode<T>* add=new ListNode<T>(value);
    tail->SetLink(add);
    tail=tail->GetLink();
    tail->SetLink(head);
    if(tail!=nullptr)
        return true;
    else
        return false;
}

template<class T>
void CirList<T>::RemoveThis()
{
    if(cur==head) //表头结点不可以删除
        cur=cur->GetLink();

    ListNode<T>* precur=cur;
    ListNode<T>* node_del=cur;

    //由于是单向循环列表，前一个结点需要遍历整个列表
    for(int i=0;i<this->GetCount();i++)
        precur=precur->GetLink();

    precur->SetLink(cur->GetLink());

    delete node_del;
    cur=precur->GetLink();

    precur=nullptr;
}

template<class T>
void CirList<T>::RemoveAll()
{
    SetBegin();
    int length=GetCount();
    for(int i=0;i<length;++i)
        RemoveThis();
    cur=head;
}


template<class T>
void CirList<T>::SetBegin()
{
    cur=head;
}

template<class T>
int CirList<T>::GetCount()
{
    int num=0;
    if(cur==nullptr)
        this->SetBegin();
    ListNode<T>* here=cur;
    while(cur->GetLink()!=here)
        {
            cur=cur->GetLink();
            num++;
        }
        cur=cur->GetLink();
        return num;
}


template<class T>
ListNode<T>* CirList<T>::GetCur()
{
    return cur;
}


template<class T>
bool CirList<T>::IsEmpty()
{
    return GetCount()==0;
}


//返回当前结点的数据，并移向下一个
template<class T>
T CirList<T>::GetNext()
{
 if(cur==head)
    cur=cur->GetLink();

    T num=cur->GetData();
    cur=cur->GetLink();
    return num;
}

template<class T>
void CirList<T>::print()
{
    if(head==tail)
        return;

     ListNode<T>* temp=head->GetLink();
     while(temp!=tail->GetLink())
        {
            cout<<temp->GetData()<<" ";
            temp=temp->GetLink();
        }
        cout<<endl;
}
