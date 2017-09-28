#ifndef LISTSTACK_HPP_INCLUDED
#define LISTSTACK_HPP_INCLUDED

#include <iostream>
#include "LinkedList.hpp"
#include "Constants.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   ListStack Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017
*/
/* ListStack template */
/* Class definition */
template <class T>
class ListStack{
    LinkedList<T> llist;
public:
    bool isEmpty();
    void push(T);
    void pop();
    void plusTopTwo();
    void minusTopTwo();
    void multiplyTopTwo();
    void divideTopTwo();
    T topItem();
};

template <class T>
bool ListStack<T>::isEmpty(){
    return llist.isEmpty();
}

template <class T>
void ListStack<T>::push(T d){
    llist.insertFront(d);
}

template <class T>
void ListStack<T>::pop(){
    llist.delFrontNode();
}

template <class T>
T ListStack<T>::topItem(){
    return llist.frontNode();
}

template <class T>
void ListStack<T>::plusTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 + top1);
}

template <class T>
void ListStack<T>::minusTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 - top1);
}

template <class T>
void ListStack<T>::multiplyTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 * top1);
}

template <class T>
void ListStack<T>::divideTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 / top1);
}

#endif // LISTSTACK_HPP_INCLUDED
