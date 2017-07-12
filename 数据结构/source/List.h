#ifndef LIST_H
#define LIST_H

#include"ListNode.h"
template<class T>
class List
{
    ListNode<T> *head;
    ListNode<T> *tail;
public:
    List();
    ~List();

    bool AddTail(T value);          //��β��ӽ��
    bool RemoveTail();              //ɾ����β���
    bool InsertAt (int index,T value);
    bool RemoveAt(int index);

    T& GetAt(int index);
    bool Isempty();
    int GetCount();
    void RemoveAll();

    ListNode<T>* GetHead();
    ListNode<T>* GetTail();
    ListNode<T>* GetNodeAt(int index);
    void print();
};

#endif // LIST_H
