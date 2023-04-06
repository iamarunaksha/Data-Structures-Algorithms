#include<iostream>
using namespace std;

//1 -> Even
// 0 -> odd

bool isEven(int a) {

    //odd
    if(a&1) {
        return 0;
    }

    //even
    else { 
        return 1;
    }

}

int main() {
    
    int num;
    cout<<"\nEnter the no. that you want to check for even/odd : ";
    cin >> num;

    cout<<endl;

    if(isEven(num)) {
        cout<<num<<" is Even"<<endl;
    }
    else {
        cout<<num<<" is Odd"<<endl;
    }

    cout<<endl;
    
    return 0;
}