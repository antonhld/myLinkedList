#ifndef CNODE_H
#define CNODE_H

template <class T>
class CNode
{
    T data_;
    CNode* previous_;
    CNode* next_;
public:
    explicit CNode();

    const T& data() const;
    void setData(const T &data);

    CNode *previous() const;
    void setPrevious(CNode *previous);

    CNode *next() const;
    void setNext(CNode *next);
};

template <class T>
CNode<T>::CNode() : data_(T()),
                    previous_(nullptr),
                    next_(nullptr)

{

}
template <class T>
const T& CNode<T>::data() const
{
    return data_;
}
template <class T>
void CNode<T>::setData(const T &data)
{
    data_ = data;
}
template <class T>
CNode<T> *CNode<T>::previous() const
{
    return previous_;
}
template <class T>
void CNode<T>::setPrevious(CNode<T> *previous)
{
    previous_ = previous;
}
template <class T>
CNode<T> *CNode<T>::next() const
{
    return next_;
}
template <class T>
void CNode<T>::setNext(CNode<T>* next)
{
    next_ = next;
}

#endif // CNODE_H
