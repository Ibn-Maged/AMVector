#include <bits/stdc++.h>
#include "AMVector.h"

using namespace std;

template <typename T>
AMVector<T>::AMVector(int n)
{
    Capacity = n;
    Size = 0;
    ptr = new T[Capacity];
}

template <typename T>
AMVector<T>::AMVector(T* arr, int n)
{
    Capacity = 10;
    Size = n;
    ptr = new T[Capacity];
    for (int i = 0; i < n; i++)
    {
        ptr[i] = arr[i];
    }
}

template <typename T>
T& AMVector<T>::operator[](int i)
{
    if (i < Size)
    {
        return *(ptr + i);
    }
    else 
    {
        // throw exception 
    }

}

template <typename T>
int AMVector<T>::push_back(T value){
    
    if(Size==Capacity){
        Capacity++;
    }
    else{
        ptr[Size]=value;
        Size++;

    }
    return value;
}


template <typename T>
T AMVector<T>::pop_back(){
    
    if(Size==0){
        // throw exaption
    }
    else{
        ptr[Size-1]=0;
        Size--;

    }
    return ptr[Size-1];
}



template <typename T>

void AMVector<T>::clear(){
    delete [] ptr;
    Size = 0;
    Capacity = 0;
}


template <typename T>

int AMVector<T>::size(){
    return Size;
}
template <typename T>

int AMVector<T>::capacity(){
    return Capacity;
}

template <typename T>

bool AMVector<T>::empty(){
    if (Size==0)
    return true;
    
    return false;
}

template <typename T>

int AMVector<T>::resize(){

    Capacity +=10;
    Size +=5;


    return Size;

}



template <class T>
ostream& operator<< (ostream& out,  AMVector<T>& v){
        for(int i=0 ; i<v.size(); i++){
        out<< v[i]<<" ";
    }

    return out;
}





