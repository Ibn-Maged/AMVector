#include <bits/stdc++.h>
#include "AMVector.cpp"


using namespace std;

int main()
{


    vector <int> s{1,12,4,78,5,7,23};
    // cout << *(s.end());
    int arr[] = {4,6,2,5,1};
    AMVector <int> v(arr, 5);
    
    cout<<v<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    v.push_back(45);
     cout<<v<<endl;
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
    /*sort(v.begin(), v.end());
    cout<<v<<endl;
    int sum=0;
    cout <<accumulate(v.begin() , v.end() , sum)<<endl;
    int arr1[] = {4,6,2,5,1 ,4,6,8,4};
    AMVector <int> v1(arr1, 9);
    int count_4 = count(v1.begin(), v1.end(),4);
    cout<<count_4<<endl;
    swap(v ,v1);
    cout<<v<<endl;
    cout<<v1<<endl;
    reverse(v1.begin(), v1.end());
    cout<<v1<<endl;
    cout<<*(++v1.begin())<<endl;
    */
    

   
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