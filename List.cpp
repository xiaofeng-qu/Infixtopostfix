#include "List.hpp"
/*
   COPYRIGHT (C) 2017 Xiaofeng Qu (xq6 ) All rights reserved.
   List Template
   Author.  Xiaofeng Qu
            xq6@zips.uakron.edu
   Version. 2.0 09.18.2017

*/
/* Implementation of the List class */
template <class T>
List<T>::List(const List &l){
    item = new T[MAX_EXPRESSION_LENGTH];
    itemNumber = l.length() - 1;
    for(int i=0; i<l.length(); i++){
        item[i] = l.item[i];
    }
}

template <class T>
void List<T>::append(T it){
    itemNumber++;
    item[itemNumber] = it;
}

template <class T>
T& List<T>::operator[](int n){
    if(n >= length()) throw "Index out of bound.";
    return item[n];
}

//template <class T>
//void List<T>::setItemAtN(T it, int n){
//    item[n] = it;
//}

//template <class T>
//T List<T>::itemAtN(int n){
//    return item[n];
//}

template <class T>
void List<T>::printList(){
    for(int i=0; i<length(); i++){
        std::cout << item[i] << " ";
    }
}

template <class T>
void List<T>::delNode(T it){
    int index = find(it);
    if(index==-1) return;
    for(int i=index; i<length()-1; i++){
        item[i] = item[i+1];
    }
    itemNumber--;
}

template <class T>
void List<T>::delNodeAtN(int n){
    for(int i=n; i<length()-1; i++){
        item[i] = item[i+1];
    }
    itemNumber--;
}

template <class T>
bool List<T>::isEmpty(){
    return itemNumber == -1;
}

template <class T>
int List<T>::length() const{
    return itemNumber+1;
}

template <class T>
int List<T>::find(T it){
    for(int i=0; i<length(); i++){
        if(item[i]==it){
            return i;
        }
    }
    return -1;
}
