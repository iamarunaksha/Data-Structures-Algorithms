#include<iostream>
#include<iomanip>
using namespace std;

int main() {

    int a = 4;
    int b = 44;
    int c = 444;
    int d = 4444;
    int e = 44444;


    cout<<setw(5)<<a<<endl;             //endl is a manipulator
    cout<<setw(5)<<b<<endl;
    cout<<setw(5)<<c<<endl;
    cout<<setw(5)<<d<<endl;
    cout<<setw(5)<<e<<endl;

    return 0;
}