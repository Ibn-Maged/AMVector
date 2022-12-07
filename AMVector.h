#ifndef AMVECTOR_H
#define AMVECTOR_H
using namespace std;

template <class T>

class AMVector 
{
private:
    int Size;
    int Capacity = 10;
    T* ptr;
    typedef T* iterator;

public:
    // Constructors and Big 4 
    AMVector (){};
    // Mohamed
    AMVector (int);			// Initialize by specific capacity
    // No content is added, size = 0
    // Assign a default size value
    AMVector (T* arr, int  n);		// Initialize by n items from array 
    AMVector (const AMVector& anotherVector);	// Initialize with a copy
    //~AMVector();				// Delete allocated memory
    AMVector<T> &operator=(const AMVector& v);  // Copy assignment  
    AMVector<T> &operator=(const AMVector&& v); // Move assignment 

    // Access operations 
    T& operator[](int i); // Access item by reference 
    // Throw an exception if out of range 

    // Ahmad
    // Modifying operations 
    int push_back(T value); // Add item to end of vec & return # of items 
                           // Increase capacity of needed
    T pop_back();     // Remove and return last element in vec 
    void erase(iterator it);        // Remove item at iterator
                                    // Throw exception if invalid iter 
    void erase(iterator it1, iterator it2);     // Remove items between 
    // iterator 1 <= iterator 2 otherwise do nothing
    // Throw exception if any iterator outside range
    void clear();                            // Delete all vector content
    void insert(iterator it, T value);       // Insert item at iterator 
    // Throw exception if invalid 

    // Iterators 		// Supports *, + and ++ operations at least
    // Can use: typedef T* iterator 
    // Or u can use std::iterator so you can 
    // apply STL algorithms on AMVector
    // Mohamed
    iterator begin();	// Return an iterator (T*) 
    iterator end();	    // Return an iterator (T*) 

    // Comparison operations 
    bool operator==(const AMVector<T>& anotherVector); // Return true if ==  
    bool operator<(const AMVector<T>& anotherVector);  // Compares item by item
    bool operator>(const AMVector<T>& anotherVector);  // Compares item by item
    // Return true if first different item in this is < in other

    // Ahmad
    // Capacity operations 
    int size();     // Return current size of vec
    int capacity(); // Return size of current allocated array  
    int resize();         // Relocate to bigger space
    bool empty();         // Return true if size is 0

    // Friends 
    friend ostream& operator << (ostream& out, AMVector<T> v);
};
//#include "AMvector.cpp"
#endif
