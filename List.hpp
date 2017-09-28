#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED
#include <iostream>
#include "Constants.hpp"
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
    ~List(){
        delete[] item;
    }
    void append(T);
    // void setItemAtN(T, int);
    // T itemAtN(int);
    T &operator[](int);
    void printList();
    void delNode(T);
    void delNodeAtN(int);
    bool isEmpty();
    int length();
    int find(T);
};

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
int List<T>::length(){
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

#endif // LIST_HPP_INCLUDED
