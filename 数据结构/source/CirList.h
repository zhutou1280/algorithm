#ifndef CIRLIST_H
#define CIRLIST_H

#include"ListNode.h"

template<class T>
class CirList
{
    ListNode<T>* head;
    ListNode<T>* tail;
    ListNode<T>* cur;

public:
    CirList();
    ~CirList();

    bool AddTail(T value);
    void RemoveThis();
    void RemoveAll();
    void SetBegin();
    int GetCount();
    ListNode<T>* GetCur();

    bool IsEmpty();
    T GetNext();
    void print();
};

#endif // CIRLIST_H

