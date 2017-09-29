#include "LinkedList.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   LinkedList Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017

*/
/* Linkedlist template */
/* Implementation of LinkedList Class */
template <class T>
LinkedList<T>::LinkedList(const LinkedList &ll) {
    head = nullptr;
    tail = nullptr;
    DataPoint *dataNode;
    dataNode = ll.head;
    while(dataNode){
        append(dataNode->data);
        dataNode = dataNode->next;
    }
}

template <class T>
void LinkedList<T>::append(T d){
    DataPoint *newNode;
    newNode = new DataPoint();
    newNode->data = d;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <class T>
void LinkedList<T>::insertFront(T d){
    DataPoint *newNode;

    newNode = new DataPoint();
    newNode->data = d;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else{
        DataPoint *dataNode;
        dataNode = head;
        head = newNode;
        newNode->next = dataNode;
    }
}

template <class T>
void LinkedList<T>::printList(){
    DataPoint *dataNode;
    dataNode = head;
    while(dataNode){
        std::cout << dataNode->data;
        dataNode = dataNode->next;
    }
}

template <class T>
void LinkedList<T>::delFrontNode(){
    if(head){
        if(head->next){
            DataPoint *dataNode;
            dataNode = head;
            head = head->next;
            delete dataNode;
            dataNode = nullptr;
        }
        else{
            delete head;
            head = nullptr;
            tail = nullptr;
        }
    }
}

template <class T>
void LinkedList<T>::delNode(T d){
    DataPoint *dataNode;
    DataPoint *previous;
    previous = nullptr;
    dataNode = head;
    while(dataNode){
        if(dataNode->data == d){
            if(previous){
                if(dataNode->next){
                    previous->next = dataNode->next;
                    delete dataNode;
                    dataNode = nullptr;
                }
                else{
                    tail = previous;
                    delete dataNode;
                    dataNode = nullptr;
                    tail->next = nullptr;
                }
            }
            else{
                if(dataNode->next){
                    head = dataNode->next;
                    delete dataNode;
                    dataNode = nullptr;
                }
                else{
                    delete dataNode;
                    dataNode = nullptr;
                    head = nullptr;
                    tail = nullptr;
                }
            }
            return;
        }
        previous = dataNode;
        dataNode = dataNode->next;
    }
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return head == nullptr;
}

template <class T>
T LinkedList<T>::frontNode(){
    return head->data;
}
