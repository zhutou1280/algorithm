#include "DouList.h"
#include<iostream>

using namespace std;

template<class T>
DouList<T>::DouList()
{
    head=tail=new DouListNode<T>;
    cur=head;
    head->SetLink(head);
    head->SetPrior(tail);
}


template<class T>
DouList<T>::~DouList()
{
    RemoveAll();
    delete head;

}

template<class T>
bool DouList<T>::AddTail(T value)
{

    DouListNode<T>* add=new DouListNode<T>(value);
    tail->SetLink(add);
    add->SetPrior(tail);
    tail=tail->GetLink();
    tail->SetLink(head);

    head->SetPrior(add);
    if(tail==NULL)
        return true;
    else
        return false;

}

template<class T>
bool DouList<T>::AddHead(T value)
{
 DouListNode<T>* add=new DouListNode<T>(value);
 add->SetPrior(head);
 add->SetLink(head->GetLink());

 head->GetLink()->SetPrior(add);
 head->SetLink(add);

    if(tail==head)
        tail=head->GetLink();
    if(add!=NULL)
        return true;
    else
        return false;
}

template<class T>
void DouList<T>::RemoveThis(bool direction)
{
    if(cur==head)
    {
        if(direction==0)
            cur=cur->GetLink();
        if(direction==1)
            cur=cur->GetPrior();
    }

    DouListNode<T>* precur=NULL;
    DouListNode<T>* nextcur=NULL;
    precur=cur->GetPrior();
    nextcur=cur->GetLink();
    DouListNode<T>* node_del=cur;
    precur->SetLink(cur->GetLink());
    nextcur->SetPrior(cur->GetPrior());

    if(direction==0)
        cur=nextcur;
    else
        cur=precur;
    delete node_del;
}


template<class T>
void DouList<T>::RemoveAll()
{
 SetBegin();
 int length=GetCount();
 for(int i=0;i<length;i++)
        RemoveThis(0);

    cur=head;
}

template<class T>
void DouList<T>::SetBegin()
{
    cur=head;

}


template<class T>
int DouList<T>::GetCount()
{
    int num=0;
    DouListNode<T>* here=cur;
    while(here->GetLink()!=cur)
    {
        here=here->GetLink();
        num++;
    }
    return num;
}

template<class T>
void DouList<T>::TowardCur()
{
    cur=cur->GetLink();

}

template<class T>
void DouList<T>::BackCur()
{
    cur=cur->GetPrior();

}

template<class T>
DouListNode<T>* DouList<T>:: GetCur()
{
    return cur;
}

template<class T>
DouListNode<T>* DouList<T>::GetHead()
{
    return head;

}

template<class T>
DouListNode<T>* DouList<T>::GetTail()
{
    return tail;

}


template<class T>
void DouList<T>::InsertAfter(T value)
{
    DouListNode<T>* add=new DouListNode<T>(value);
    DouListNode<T>* nextcur=cur->GetLink();
    cur->SetLink(add);
    add->SetLink(nextcur);
    add->SetPrior(cur);
    nextcur->SetPrior(add);

    if(tail==cur)
            tail=cur->GetLink();
}

template<class T>
bool DouList<T>::IsEmpty()
{
    return head->GetLink()==head;
}

template<class T>
T DouList<T>::GetNext()
{

    if(head==cur)
        cur=cur->GetLink();
    T num=cur->GetData();
    cur=cur->GetLink();
    return num;
}

template<class T>
T DouList<T>::GetPrior()
{
    if(cur==head)
        cur=cur->GetPrior();
    T num=cur->GetData();
    cur=cur->GetPrior();
    return num;

}

template<class T>
void DouList<T>::print()
{
    DouListNode<T>* here=head->next;
    while(here!=head)
    {
        cout<<here->GetData();
        here=here->GetLink();
    }
    cout<<endl;
}


