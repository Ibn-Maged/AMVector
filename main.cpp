#include <bits/stdc++.h>
#include "AMVector.cpp"

using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    AMVector<int> v1(arr, 5);

    cout << "Hello, World.\n" << v1[4];
}