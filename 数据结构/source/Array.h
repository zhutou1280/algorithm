#ifndef ARRAY_H
#define ARRAY_H

#include<cstdlib>
#include<iostream>
using namespace std;

const int DefaultSize=100;

template<class Type>
class Array
{
    Type* elements;
    int ArraySize;
public:
    Array(int Size=DefaultSize);
    Array(const Array<Type>& x);
    ~Array(){delete []elements;}
    Array<Type>& operator= (const Array<Type>& rhs);
    Type& operator[] (int i);
    int length() const {return ArraySize;}
    void Resize(int sz);

};



#endif // _ARRAY_H



