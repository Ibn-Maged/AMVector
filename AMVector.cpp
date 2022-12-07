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
    if (i < Size)
    {
        return *(ptr + i);
    }
    else 
    {
        // throw exception 
    }
}