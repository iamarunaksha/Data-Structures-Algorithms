#include<iostream> // # - Preprocessor directive | iostream - header file
using namespace std; // "::var._name" scope resolution operator, used for calling global variable with same name as local variable

int main() // Execution of code begins from main function (Mandatory for any program)
{
    int a; //Declaration of variables
    cout<<"\nSize of 'int' (in bytes) : " <<sizeof(a)<<endl; 

    float b;
    cout<<"Size of 'float' (in bytes) : " <<sizeof(b)<<endl;    //if one writes 35.8f then its considered as float otherwise only 35.8 is taken as double by default

    char c;
    cout<<"Size of 'char' (in bytes) : " <<sizeof(c)<<endl;

    bool d;
    cout<<"Size of 'boolean' (in bytes) : " <<sizeof(d)<<endl;

    short int s;
    cout<<"Size of 'short int' (in bytes) : " <<sizeof(s)<<endl;

    long int l;
    cout<<"Size of 'long int' (in bytes) : " <<sizeof(l)<<endl;    //l is used for long double along with no. e.g., 86.9l

    double p;
    cout<<"Size of 'double' (in bytes) : " <<sizeof(p)<<endl;

/*
    int x = 7;
    int &y = x;     //&y is a reference variable, such that value of x & y is same 

    const m =7;    //with const, value of m cannot be overriden anywhere in the program
    m = 8;        // this statement won't be executed

    setw(no.) ---> this shifts the no.s/char 'no.' places to the right, for this use #include<iomanip>

*/

    return 0;

}