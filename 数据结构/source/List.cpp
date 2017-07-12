
#include"List.h"
#include<iostream>
#include<cstdlib>

using namespace std;

template<class T>
List<T>::List()
{
    head=new ListNode<T>();
    tail=head;
    tail->SetLink(NULL);
}

template<class T>
List<T>::~List()
{
    RemoveAll();
    delete head;
}



template<class T>
bool List<T>::AddTail(T value)
{
    ListNode<T>* add=new ListNode<T> (value);
    tail->SetLink(add);
    tail=tail->GetLink();
    tail->SetLink(NULL);
    if(tail!=NULL)
        return true;
    else
        return false;
}


template<class T>
bool List<T>::RemoveTail()
{
    return RemoveAt(this->GetCount()-1);
}

template<class T>
void List<T>::RemoveAll()
{
    ListNode<T>*  cur;
    while(head->GetLink()!=nullptr)
    {
     cur=head->GetLink();
     head->SetLink(cur->GetLink());
     delete cur;
    }
    tail=head;
}


template<class T>
bool List<T>::InsertAt(int index,T value)
{
    if(index>this->GetCount()-1||index<0)
        {
            cout<<"wrong position"<<endl;
           return false;
        }

        ListNode<T>* cur=head;
        while(index--)
        {
            cur=cur->GetLink();
        }

       ListNode<T>* add=new ListNode<T>(value);
       add->SetLink(cur->GetLink());
       cur->SetLink(add);

       if(cur->GetLink()==NULL)
            return false;
       else
           return true;
}


template<class T>
bool List<T>::RemoveAt(int index)
{
    if(index>this->GetCount()-1||index<0)
        {
            cout<<"wrong position"<<endl;
            return false;
        }
    ListNode<T>* cur,*curprev;
    cur=head;
    curprev=cur->GetLink();

    while(index--)
    {
        cur=cur->GetLink();
        curprev=cur->GetLink();
    }

   if(tail==curprev)
       tail=cur;
    cur->SetLink(curprev->GetLink());
    delete curprev;

    if(curprev!=NULL)
        return true;
    else
        return false;

}






template<class T>
T& List<T>::GetAt(int index)
{
    if(index>this->GetCount()-1||index<0)
        cout<<"wrong position"<<endl;

    ListNode<T>* cur=head->GetLink();
    while(index)
     {
        cur=cur->GetLink();
        index--;
     }
    return cur->GetData();
}



template<class T>
bool List<T>::Isempty()
{
    return head->GetLink()==NULL;
}


template<class T>
int List<T>::GetCount()
{
    int count=0;
    ListNode<T>* cur=head->GetLink();
    while(cur!=NULL)
    {
        ++count;
        cur=cur->GetLink();
    }
    return count;
}






template<class T>
ListNode<T>* List<T>::GetHead()
{
    return head;
}


template<class T>
ListNode<T>* List<T>::GetTail()
{
    return tail;
}

template<class T>
ListNode<T>* List<T>::GetNodeAt(int index)
{
    if(index>this->GetCount()-1||index<0)
    {
        cout<<"a wrong position"<<endl;
        exit(1);
    }
    ListNode<T>* cur=head->GetLink();
    while(index--)
        cur=cur->GetLink();
    return cur;
}

template<class T>
void List<T>::print()
{
    ListNode<T>* cur=head->GetLink();
    while(cur!=tail->GetLink())
    {
        cout<<cur->GetData()<<" ";
        cur=cur->GetLink();
    }
    cout<<endl;
}





