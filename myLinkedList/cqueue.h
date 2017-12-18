#ifndef CQUEUE_H
#define CQUEUE_H

#include "cmylist.h"

template <class T>
class CQueue
{
    CMyList<T> list_;
public:
    const T& front();
    const T& back();
    T pop();
    void push(const T& value);
    int getSize();
    bool isEmpty();
};

template <class T>
const T& CQueue<T>::front()
{
    return list_.getFirst();
}

template <class T>
const T& CQueue<T>::back()
{
    return list_.getLast();
}

template <class T>
T CQueue<T>::pop()
{
    T last = list_.getFirst();
    list_.deleteAt(0);
    return last;
}

template <class T>
void CQueue<T>::push(const T& value)
{
    list_.pushBack(value);
}

template <class T>
int CQueue<T>::getSize()
{
    return list_.getSize();
}

template <class T>
bool CQueue<T>::isEmpty()
{
    return list_.isEmpty();
}

#endif // CQUEUE_H
