
template<class T>
class DouListNode
{
    T Data;
    DouListNode* link;
    DouListNode* prior;
public:
    DouListNode():link(nullptr),prior(nullptr){}
    DouListNode(T value):link(nullptr),prior(nullptr),Data(value){}
    ~DouListNode(){}
    void SetLink(DouListNode<T>* next);
    void SetPrior(DouListNode<T>* pre);
    DouListNode<T>* GetLink();
    DouListNode<T>* GetPrior();
    T& GetData();
};



template<class T>
void DouListNode<T>::SetLink(DouListNode<T>* next)
{
    link=next;
}

template<class T>
void DouListNode<T>::SetPrior(DouListNode<T>* pre)
{
    prior=pre;
}

template<class T>
DouListNode<T>* DouListNode<T>::GetLink()
{
    return link;

}

template<class T>
DouListNode<T>* DouListNode<T>::GetPrior()
{
    return prior;
}


template<class T>
T& DouListNode<T>::GetData()
{
    return Data;
}


