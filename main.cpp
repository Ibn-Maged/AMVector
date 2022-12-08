#include <bits/stdc++.h>
#include "AMVector.cpp"

using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};
    AMVector<int> v1(arr, 5);
    cout<<v1<<endl;
    v1.push_back(25);
    cout<<v1[5]<<endl;
    cout<<v1<<endl;

    v1.pop_back();
    cout<<v1[4]<<endl;

    v1.clear();
    cout<<v1[0]<<endl;

    std::cout << *(v1.begin()) << ' ' << *(v1.end());

    auto x = v1.begin();
    x++;
    cout << '\n' << *x;

    
}