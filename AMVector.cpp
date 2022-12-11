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
    
    try
    {
        if(i >= Capacity)
        {
            throw "Error Index Out of Range";
        }
        return *(ptr + i);
    }
    catch(const char* e)
    {
        std::cerr<< e << '\n';
    }
    
    // if (i < Capacity)
    // {
    //     return *(ptr + i);
    // }
    // else 
    // {
    //     // throw exception 
    // }
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
    
    ptr[Size]=value;
    Size++;

    
    return Size;
}


template <typename T>
T AMVector<T>::pop_back(){
    
    try{
        if(Size==0){
            throw "The vector is empty";   
        }
    
        Size--;
        return ptr[Size-1];
    }
    catch(const char* e)
    {
        std::cerr<< e << '\n';
    }

    
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

void AMVector<T>::resize(){

    Capacity = Capacity*2;
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

    try{
        if(it < begin() or it> end()-1){
            throw "invaild iterator";
            
        }


        if  (it==end()-1){
            Size--;

        }

        else {
            for (auto x = it ; x!=end()-1; x++ ){

            *x = *(x+1);
            
        }
            Size--;

        }
    }
    catch(const char* e)
    {
        std::cerr<< e << '\n';
    }


}

template <class T>

void AMVector<T>::erase(iterator it1,iterator it2){
    try{
        if ((it1 < begin() or it1> end()-1) or (it2 < begin() or it2> end()-1)){
            throw "invaild interval";
        }
        else if (it1==it2){
            erase(it1);
        }
        else if(it1>it2){
            return;
        }
        else{
        auto y=it2+1;
        for (auto x = it1 ; x!=it2 ;x++ ){
            *x = *(y);
            y++;
            Size--; 
        }
            Size--;

        }

    }
    catch(const char* e)
    {
        std::cerr<< e << '\n';
    }

}

template <class T>
void AMVector<T>::insert(iterator it, T value){
    try{
    if(Size==Capacity)
    resize();
    auto y= (ptr + Capacity - 1);
    if(it>y or it<begin()){
        throw "insert out of capasity";
    }
    else if(it==end()){
        push_back(value);
    }
    else if (it <= y and it > end()-1){
        *it = value;
        return;
    }
    else{
        for (auto x = end()-1 ; x!=(it-1); x-- ){
            *(x+1)= *x;
    }
    *it= value;
    Size++;
    }
    }
    catch(const char* e)
    {
        std::cerr<< e << '\n';
    }
    
}

