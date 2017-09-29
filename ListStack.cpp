#include "ListStack.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   ListStack Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017
*/
/* ListStack template */
/* Implementation of ListStack Class */
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
    if ( top1 == 0.0 )
        throw "Denominator cannot be zero.";
    pop();
    int top2 = topItem();
    pop();
    push(top2 / top1);
}
