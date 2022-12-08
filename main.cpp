#include <bits/stdc++.h>
#include "AMVector.cpp"

using namespace std;

int main()
{
    int arr[7] = {1,12,4,78,5,7,23};
    AMVector<int> v1(arr, 7);
    int arr1[7] = {1,12,7,78,5,7,23};
    AMVector<int> v2(arr1, 7);
    AMVector<int>* ptr = &v1;
    ptr++;
    cout<<v1<<endl;
    v1.push_back(25);
    cout<<v1[5]<<endl;
    cout<<v1<<endl;

    v1.pop_back();
    cout<<v1[4]<<endl;

    //v1.clear();
    cout<<v1[0]<<endl;
   

    std::cout << *(v1.begin()) << ' ' << *(v1.end())<<endl;
   

    cout<<endl;
    cout<<endl;
    v1.insert(v1.begin()+9 , 235);
    cout<<v1<<endl;
}