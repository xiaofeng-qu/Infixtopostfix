#ifndef LISTSTACK_HPP_INCLUDED
#define LISTSTACK_HPP_INCLUDED

#include <iostream>
#include "LinkedList.hpp"
#include "LInkedList.cpp"
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
#endif // LISTSTACK_HPP_INCLUDED
