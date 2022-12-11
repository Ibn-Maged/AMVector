#include <bits/stdc++.h>
#include "AMVector.cpp"


using namespace std;

int main()
{


    vector <int> s{1,12,4,78,5,7,23};
    // cout << *(s.end());
    int arr[] = {1,2,3,4,5};
    AMVector <int> v(arr, 5);
    cout << v[0] << '\n';
    cout << v[8];
    /*int arr[7] = {1,12,4,78,5,7,23};
    AMVector<int> v1(arr, 7);
        std::cout << *(v1.begin()) << ' ' << *(v1.end())<<endl;

    if(binary_search(v1.begin() , v1.end()+1 , 5))  // problem
        cout<<"yeeeees"<<endl;
    sort(v1.begin() , v1.end()+1);  // problem    +1
    cout<<v1<<endl;
    std::cout << *(v1.begin()) << ' ' << *(v1.end())<<endl;
    int sum=0;
    cout <<accumulate(v1.begin() , v1.end()+1 , sum)<<endl;
    */



    /*int arr1[7] = {1,12,7,78,5,7,23};
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
   

    std::cout << *(++v1.begin()) << ' ' << *(v1.end())<<endl;

   

    cout<<endl;
    cout<<endl;
    v1.insert(v1.begin()+9 , 235);
    cout<<v1<<endl;
    */
}