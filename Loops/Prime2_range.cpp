#include<iostream>
using namespace std;

int main() //Loops
{
    int a,b;
    cout<<"\nEnter the lower limit : ";
    cin>>a;

    cout<<"Enter the upper limit : ";
    cin>>b;

    cout<<"\nThe prime no.s in the given range are : "<<endl;

    for(int num=a; num<=b; num++){
        int i;
        for(i=2; i<num; i++){
            if(num%i==0){
                break;
            }
        }
            if(i==num){
                cout<<num<<endl;
            }
    }

}
