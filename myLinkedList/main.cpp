#include <QCoreApplication>
#include <iostream>
#include "cmylist.h"
#include "cstack.h"
#include "cqueue.h"
#include "cpriorityqueue.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout<<"Testing list: \n";
    CMyList<int> list;
    list.pushFront(10);
    list.pushBack(5);

    list.pushBack(7);
    list.pushFront(1);

    list.pushFront(3);

    list.insertAfter(2, 8);

    for(int i=0; i<list.getSize(); i++)
        std::cout<<list.atPos(i)<<"   ";
    std::cout<<'\n';
    list.deleteAt(3);
    for(int i=0; i<list.getSize(); i++)
        std::cout<<list.atPos(i)<<"   ";
    std::cout<<'\n';
    CMyList<int> list2 = list;
    list.clear();
    std::cout<<list.isEmpty()<<"   "<<list.getSize()<<'\n';
    std::cout<<'\n';
    for(int i=0; i<list2.getSize(); i++)
        std::cout<<list2.atPos(i)<<"   ";
    std::cout<<'\n';

    std::cout<<"Testing stack: \n";
    CStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(6);
    std::cout<<"size: "<<stack.getSize()<<"   ";
    std::cout<<"top: "<<stack.top()<<"   ";
    std::cout<<"pop: "<<stack.pop()<<'\n';
    std::cout<<"size: "<<stack.getSize()<<"   ";
    std::cout<<"top: "<<stack.top()<<'\n';

    std::cout<<"Testing queue: \n";
    CQueue<int> queue;
    queue.push(2);
    queue.push(4);
    queue.push(8);
    std::cout<<"size: "<<queue.getSize()<<"   ";
    std::cout<<"front: "<<queue.front()<<"   ";
    std::cout<<"pop: "<<queue.pop()<<'\n';
    std::cout<<"size: "<<queue.getSize()<<"   ";
    std::cout<<"front: "<<queue.front()<<'\n';

    std::cout<<"Testing priority queue: \n";
    CPriorityQueue<int> priorityQueue;
    priorityQueue.push(2);
    priorityQueue.push(4);
    priorityQueue.push(8);
    std::cout<<"size: "<<priorityQueue.getSize()<<"   ";
    std::cout<<"front: "<<priorityQueue.front()<<"   ";
    std::cout<<"pop: "<<priorityQueue.pop()<<'\n';
    std::cout<<"size: "<<priorityQueue.getSize()<<"   ";
    std::cout<<"front: "<<priorityQueue.front()<<'\n';

    return a.exec();
}
