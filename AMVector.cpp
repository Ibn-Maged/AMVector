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
    Capacity = n;
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
    if (i < Capacity)
    {
        return *(ptr + i);
    }
    else 
    {
        // throw exception 
    }
}

// copy Constructor
template <typename T>
AMVector<T>::AMVector(const AMVector& anotherVector)
{
    cout << "Copy Constructor Called!\n";
    this->Size = anotherVector.Size;
    this->Capacity = anotherVector.Capacity;
    ptr = new T[Capacity];
    for (int i = 0; i < Size; i++)
    {
        ptr[i] = anotherVector.ptr[i];
    }
}

template <typename T>
AMVector<T>& AMVector<T>::operator=(const AMVector& anotherVector)  // Copy assignment  
{
    cout << "Copy Assignment Called!\n";
    if(ptr != anotherVector.ptr)
    {
        delete[] ptr;   // to avoid memory leak
        this->Size = anotherVector.Size;
        this->Capacity = anotherVector.Capacity;
        ptr = new T[Capacity];
        for (int i = 0; i < Size; i++)
        {
            ptr[i] = anotherVector.ptr[i];
        }
    }
    return *this;
}

template <typename T>
AMVector<T>& AMVector<T>::operator=(const AMVector&& anotherVector) // Move assignment
{
    cout << "Move Assignment Called!\n";
    delete[] ptr;
    this->Size = anotherVector.Size;
    this->Capacity = anotherVector.Capacity;
    ptr = new T[Capacity];
    for (int i = 0; i < Size; i++)
    {
        ptr[i] = anotherVector.ptr[i];
    }
    return *this;
}

template <typename T>
AMVector<T>::~AMVector()
{
    cout << "Destructor Called!\n";
    delete[] ptr;
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
template <typename T>
bool AMVector<T>::operator<(const AMVector<T>& anotherVector)
{
    if(Size != anotherVector.Size)
    {
        // throw exception
    }
    else
    {
        for (int i = 0; i < Size; i++)
        {
            if (ptr[i] > anotherVector.ptr[i])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool AMVector<T>::operator>(const AMVector<T>& anotherVector)
{
    if(Size != anotherVector.Size)
    {
        // throw exception
    }
    else
    {
        for (int i = 0; i < Size; i++)
        {
            if (ptr[i] < anotherVector.ptr[i])
            {
                return false;
            }
        }
    }
    return true;
}

template <typename T>
bool AMVector<T>::operator==(const AMVector<T>& anotherVector)
{
    if (Size != anotherVector.Size)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < Size; i++)
        {
            if(ptr[i] != anotherVector.ptr[i])
            {
                return false;
            }
        }
    }
    return true;
}

template <class T>
ostream& operator<< (ostream& out,  AMVector<T>& v){
    for(int i=0 ; i<v.size(); i++){
        out<< v[i]<<" ";
    }

    return out;
}





