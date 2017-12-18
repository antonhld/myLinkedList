#ifndef CPRIORITYQUEUE_H
#define CPRIORITYQUEUE_H

#include "cmylist.h"

template <class T>
class CPriorityQueue
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
const T& CPriorityQueue<T>::front()
{
    return list_.getFirst();
}

template <class T>
const T& CPriorityQueue<T>::back()
{
    return list_.getLast();
}

template <class T>
T CPriorityQueue<T>::pop()
{
    T last = list_.getFirst();
    list_.deleteAt(0);
    return last;
}

template <class T>
void CPriorityQueue<T>::push(const T& value)
{
    if(list_.isEmpty())
        list_.pushFront(value);
    else
    {
        int i=0;
        while(list_.atPos(i) > value)
            i++;
        list_.insertAfter(i, value);
    }
}

template <class T>
int CPriorityQueue<T>::getSize()
{
    return list_.getSize();
}

template <class T>
bool CPriorityQueue<T>::isEmpty()
{
    return list_.isEmpty();
}

#endif // CPRIORITYQUEUE_H
