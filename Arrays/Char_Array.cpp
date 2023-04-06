#include<iostream>
using namespace std;

void reverse(char arr[], int n) {

    int s = 0;
    int e = n-1;

    while(s<e) {
        swap(arr[s++],arr[e--]);
    }
}

int getLength(char arr[]) {

    int count = 0;
    
    for(int i=0; arr[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {

    char name[100];

    cout<<"\nEnter your name : ";
    cin>>name;

    cout<<"\nYour name is : "<<name<<endl;

    int l = getLength(name);

    cout<<"\nLength of the string is : "<<l<<endl;

    reverse(name,l);
    cout<<"\nReversed string : "<<name;
    cout<<"\n"<<endl;

    return 0;
}