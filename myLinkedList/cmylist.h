#ifndef CMYLIST_H
#define CMYLIST_H

#include "cnode.h"

template<class T>
class CMyList
{
    CNode<T>* first_;
    CNode<T>* last_;
    int size_;
public:
    CMyList();
    ~CMyList();
    void pushFront(const T& value);
    void pushBack(const T& value);
    void insertAfter(int position, const T& value);
    const T& atPos(int position);
    const T& getFirst();
    const T& getLast();
    bool isEmpty();
    int getSize() const;
    void deleteAt(int position);
    void clear();
    CMyList& operator =(const CMyList& otherList);
};

template<class T>
CMyList<T>::CMyList() : first_(nullptr),
                        last_(nullptr),
                        size_(0)
{

}

template<class T>
CMyList<T>::~CMyList()
{
    this->clear();
}

template<class T>
void CMyList<T>::pushFront(const T& value)
{
    CNode<T>* temp = new CNode<T>;
    temp->setData(value);
    temp->setPrevious(nullptr);
    temp->setNext(first_);
    if(first_ != nullptr)
        first_->setPrevious(temp);
    first_ = temp;
    if(last_ == nullptr)
        last_ = temp;
    size_++;
}

template<class T>
void CMyList<T>::pushBack(const T& value)
{
    CNode<T>* temp = new CNode<T>;
    temp->setData(value);
    temp->setNext(nullptr);
    temp->setPrevious(last_);
    if(last_ != nullptr)
        last_->setNext(temp);
    last_ = temp;
    if(first_ == nullptr)
        first_ = temp;
    size_++;
}

template<class T>
void CMyList<T>::insertAfter(int position, const T& value)
{
    if(position >= size_)
        return;
    else if(position == 0)
    {
        pushFront(value);
        return;
    }

    CNode<T>* temp = new CNode<T>;
    CNode<T>* iter = first_;
    temp->setData(value);
    for(int i=0; i<position-1; i++)
        iter = iter->next();
    if (iter->next() == nullptr)
    {
        iter->setNext(temp);
        temp->setNext(nullptr);
        temp->setPrevious(iter);
    }
    else
    {
        temp->setNext(iter->next());
        temp->next()->setPrevious(temp);
        iter->setNext(temp);
        temp->setPrevious(iter);
    }
    size_++;
}

template<class T>
const T& CMyList<T>::atPos(int position)
{

    if(position == 0)
        return getFirst();
    else if(position == size_-1)
        return getLast();
    else
    {
        CNode<T>* iter = first_;
        for(int i=0; i<position; i++)
            iter = iter->next();
        return iter->data();
    }
}

template<class T>
const T& CMyList<T>::getFirst()
{
    return first_->data();
}

template<class T>
const T& CMyList<T>::getLast()
{
    return last_->data();
}

template<class T>
bool CMyList<T>::isEmpty()
{
    if(size_ == 0)
        return true;
    else
        return false;
}

template<class T>
int CMyList<T>::getSize() const
{
    return size_;
}

template<class T>
void CMyList<T>::deleteAt(int position)
{
    CNode<T>* temp;
    if(position >= size_)
        return;
    else if(position == 0)
    {
        temp = first_;
        temp->next()->setPrevious(nullptr);
        first_ = temp->next();
        delete temp;
    }
    else if(position == size_-1)
    {
        temp = last_;
        temp->previous()->setNext(nullptr);
        last_ = temp->previous();
        delete temp;
    }
    else
    {
        temp = first_;
        for(int i=0; i<position; i++)
            temp = temp->next();
        temp->previous()->setNext(temp->next());
        temp->next()->setPrevious(temp->previous());
        delete temp;
    }
    size_--;
}

template<class T>
void CMyList<T>::clear()
{
    CNode<T>* temp;
    while(size_ != 0)
    {
        temp = last_;
        last_ = temp->previous();
        delete temp;
        size_--;
    }
}

template<class T>
CMyList<T>& CMyList<T>::operator =(const CMyList& otherList)
{
    this->clear();
    CNode<T>* temp = otherList.first_;
    while (temp != nullptr)
    {
        this->pushBack(temp->data());
        temp = temp->next_;
    }

}

#endif // CMYLIST_H
