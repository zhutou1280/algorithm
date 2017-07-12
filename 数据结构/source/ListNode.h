
template<class T>
class ListNode
{
    T data;
    ListNode<T>* link;

public:
    ListNode():link(nullptr){}
    ListNode(T value):link(nullptr),data(value){}
    ~ListNode(){}
    void SetLink(ListNode<T>* next);
    void SetData(T value);
    ListNode<T>* GetLink();
    T& GetData();
};

template<class T>
void ListNode<T>::SetLink(ListNode<T>* next)
{
    link=next;
}

template<class T>
void ListNode<T>::SetData(T value)
{
    data=value;
}

template<class T>
ListNode<T>* ListNode<T>::GetLink()
{
    return link;
}

template<class T>
T& ListNode<T>::GetData()
{

    return data;
}

