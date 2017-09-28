#ifndef PAIREDLINKEDLIST_HPP_INCLUDED
#define PAIREDLINKEDLIST_HPP_INCLUDED
#include <iostream>
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   PairedLinkedList Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017

*/
/* PairedLinkedlist template */
/* Class definition */
template <class T>
class PairedLinkedList{
    struct DataPoint{
        T data;
        int value;
        DataPoint *next;
    };
    DataPoint *head;
    DataPoint *tail;
public:
    PairedLinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    PairedLinkedList(const PairedLinkedList &); // Copy constructor
    void append(T, int v = 0);
    void insertFront(T, int v = 0);
    void printList();
    void printListDataAndValue();
    void delFrontNode();
    void delNode(T);
    bool isEmpty();
    T frontNode();
    int frontNodeValue();
};
/* Class implementation */
template <class T>
PairedLinkedList<T>::PairedLinkedList(const PairedLinkedList &ll) {
    head = nullptr;
    tail = nullptr;
    DataPoint *dataNode;
    dataNode = ll.head;
    while(dataNode){
        append(dataNode->data, dataNode->value);
        dataNode = dataNode->next;
    }
}

template <class T>
void PairedLinkedList<T>::append(T d, int v){
    DataPoint *newNode;
    newNode = new DataPoint();
    newNode->data = d;
    newNode->value = v;
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
void PairedLinkedList<T>::insertFront(T d, int v){
    DataPoint *newNode;

    newNode = new DataPoint();
    newNode->data = d;
    newNode->value = v;
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
void PairedLinkedList<T>::printList(){
    DataPoint *dataNode;
    dataNode = head;
    while(dataNode){
        std::cout << dataNode->data << " ";
        dataNode = dataNode->next;
    }
}

template <class T>
void PairedLinkedList<T>::printListDataAndValue(){
    DataPoint *dataNode;
    dataNode = head;
    while(dataNode){
        std::cout << dataNode->data << ": " << dataNode->value << "; ";
        dataNode = dataNode->next;
    }
}

template <class T>
void PairedLinkedList<T>::delFrontNode(){
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
void PairedLinkedList<T>::delNode(T d){
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
bool PairedLinkedList<T>::isEmpty(){
    return head == nullptr;
}

template <class T>
T PairedLinkedList<T>::frontNode(){
    return head->data;
}

template <class T>
int PairedLinkedList<T>::frontNodeValue(){
    return head->value;
}
#endif // PAIREDLINKEDLIST_HPP_INCLUDED
