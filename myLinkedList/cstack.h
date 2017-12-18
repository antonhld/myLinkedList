#ifndef CSTACK_H
#define CSTACK_H

#include "cmylist.h"

template <class T>
class CStack
{
    CMyList<T> list_;
public:
    const T& top();
    T pop();
    void push(const T& value);
    int getSize();
    bool isEmpty();
};

template <class T>
const T& CStack<T>::top()
{
    return list_.getLast();
}

template <class T>
T CStack<T>::pop()
{
    T last = list_.getLast();
    list_.deleteAt(list_.getSize()-1);
    return last;
}

template <class T>
void CStack<T>::push(const T& value)
{
    list_.pushBack(value);
}

template <class T>
int CStack<T>::getSize()
{
    return list_.getSize();
}

template <class T>
bool CStack<T>::isEmpty()
{
    return list_.isEmpty();
}

#endif // CSTACK_H
