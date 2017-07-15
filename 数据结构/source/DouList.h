#include"DouListNode.h"



template<class T>
class DouList
{
    DouListNode<T>* head;
    DouListNode<T>* tail;
    DouListNode<T>* cur;
public:
    DouList();
    ~DouList();

    bool AddTail(T value);
    bool AddHead(T value);
    void RemoveAll();
    void RemoveThis(bool direction);
    void SetBegin();
    int GetCount();
    void TowardCur();
    void BackCur();
    DouListNode<T>* GetCur();
    DouListNode<T>* GetHead();
    DouListNode<T>* GetTail();
    void InsertAfter(T value);
    bool IsEmpty();
    T GetNext();
    T GetPrior();
    void print();

};



