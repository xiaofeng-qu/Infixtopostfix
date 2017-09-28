#ifndef STACK_HPP_INCLUDED
#define STACK_HPP_INCLUDED
#include <iostream>
#include "Constants.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   Stack Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017
*/
/* Stack template */
/* Class definition */
template <class T>
class Stack{
    T data[MAX_EXPRESSION_LENGTH];
    int top;
public:
    Stack(){
        top = -1;
    }
    bool isEmpty();
    bool isFull();
    void push(T);
    void pop();
    void plusTopTwo();
    void minusTopTwo();
    void multiplyTopTwo();
    void divideTopTwo();
    T topItem();
};

template <class T>
bool Stack<T>::isEmpty(){
    return top == -1;
}

template <class T>
bool Stack<T>::isFull(){
    return (top == MAX_EXPRESSION_LENGTH - 1);
}

template <class T>
void Stack<T>::push(T d){
    if(!isFull()){
        ++top;
        data[top] = d;
    }
}

template <class T>
void Stack<T>::pop(){
    if(!isEmpty()){
        --top;
    }
}

template <class T>
T Stack<T>::topItem(){
    return data[top];
}

template <class T>
void Stack<T>::plusTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 + top1);
}

template <class T>
void Stack<T>::minusTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 - top1);
}

template <class T>
void Stack<T>::multiplyTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 * top1);
}

template <class T>
void Stack<T>::divideTopTwo(){
    int top1 = topItem();
    pop();
    int top2 = topItem();
    pop();
    push(top2 / top1);
}
#endif // STACK_HPP_INCLUDED
