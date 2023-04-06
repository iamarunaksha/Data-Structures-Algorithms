#include<iostream>
using namespace std;

int main(){

    // What is a pointer? ----> Data type which holds the address of other data types
    int a = 3;
    int* b = &a;                // here, int* b is a pointer variable storing address of a.

    int &y = a;                // here &y is a reference variable, y is another name of a, if y++ then a becomes 4
                              // reference variable is an internal pointer, they cannot be updated
    // & ---> (Address of) Operator, b stores address of a through '&'. Address = Memory location
    cout<<"\nThe address of a is "<<&a<<endl;
    cout<<"\nThe address of a is "<<b<<endl;

    // * ---> (value at) Dereference operator, *b gives the value stored in a/b
    cout<<"\nThe value at address b is (using de-reference operator) : "<<*b<<endl;

    // Pointer to pointer
    int** c = &b;
    cout<<"\nThe address of b is "<<&b<<endl;
    cout<<"\nThe address of b is "<<c<<endl; 

    cout<<"\nThe value at address c is "<<*c<<endl;                         //*c gives value at b == &a
    cout<<"\nThe value at address value_at(value_at(c)) is "<<**c<<endl;    // *c = value_at(b), *b = value_at(a), **c = *(b) = a

    return 0;
}