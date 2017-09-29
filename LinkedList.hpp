#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED
#include <iostream>
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   LinkedList Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017

*/
/* Linkedlist template */
/* Class definition */
template <class T>
class LinkedList{
    struct DataPoint{
        T data;
        DataPoint *next;
    };
    DataPoint *head;
    DataPoint *tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    LinkedList(const LinkedList &); // Copy constructor
    void append(T);
    void insertFront(T);
    void printList();
    void delFrontNode();
    void delNode(T);
    bool isEmpty();
    T frontNode();
};
#endif // LINKEDLIST_HPP_INCLUDED
