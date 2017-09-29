#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include <iostream>
#include "Constants.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   List Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017

*/
/* List template */
/* Class definition */
template <class T>
class List{
private:
    T *item;
    int itemNumber;
public:
    List(){
        item = new T[MAX_EXPRESSION_LENGTH];
        itemNumber = -1;
    }
    List(const List &);
    ~List(){
        delete[] item;
        item = nullptr;
    }
    void append(T);
    // void setItemAtN(T, int);
    // T itemAtN(int);
    T &operator[](int);
    void printList();
    void delNode(T);
    void delNodeAtN(int);
    bool isEmpty();
    int length() const;
    int find(T);
};

#endif // LIST_HPP_INCLUDED
