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
    // if (i>=Size and i<Capacity)     return 0
    
    
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
        resize();
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

    Capacity = Size*2;
    


    return Capacity;

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



template <class T>

void AMVector<T>::erase(iterator it){

    if(it < begin() or it> end()){
        return;
        //invaild iteartor
        // throw exception
    }


    if  (it==end()){
        *it=0;
        Size--;

    }

    else {
        for (auto x = it ; x!=end(); x++ ){

        *x = *(x+1);
        
    }
        Size--;

    }
    

}

template <class T>

void AMVector<T>::erase(iterator it1,iterator it2){
    if ((it1 < begin() or it1> end()) or (it2 < begin() or it2> end())){
        return;
        // invailed range
        // throw exception
    }
    if (it1==it2){
        return;
    }
    else{
    auto y=it2+1;
    for (auto x = it1 ; x!=it2 ;x++ ){
        *x = *(y);
        y++;
        Size--; 
    }
    }

    Size--;

}

template <class T>
void AMVector<T>::insert(iterator it, T value){
    auto y= (ptr + Capacity - 1);
    if(it>y or it<begin()){
        return;
        //invailed iterator out of capacity 
        // throw exception
    }
    else if (it <= y and it >= begin()){
        *it = value;
        return;
    }
    else{
        for (auto x = end() ; x!=(it-1); x-- ){
            *(x+1)= *x;
    }
    *it= value;
    Size++;
    }

    

}

