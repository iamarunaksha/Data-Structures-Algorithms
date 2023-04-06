#include <iostream>
using namespace std;

void countNum(int i, int n) {
    
    if(i<1)
        return;

    countNum(i-1,n);    
    cout<<i<<endl;
}
void reverseCountNum(int i, int n) {
    
    if(i>n)
        return;
    
    reverseCountNum(i+1,n);    
    cout<<i<<endl;
    
}

int main()
{
    int n;
    cout<<"\nEnter the no. of times you want to print : ";
    cin>>n;
    
    //printName(0,5);
    //countNum(n,n);
    reverseCountNum(1,n);

    return 0;
}