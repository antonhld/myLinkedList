#include <QCoreApplication>
#include <iostream>
#include "cmylist.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CMyList<int> list;
   // std::cout<<list.isEmpty()<<"   "<<list.getSize()<<'\n';
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
        std::cout<<list[i]<<"   ";
    std::cout<<'\n';
    list.clear();
    std::cout<<list.isEmpty()<<"   "<<list.getSize()<<'\n';
    std::cout<<'\n';
    return a.exec();
}
