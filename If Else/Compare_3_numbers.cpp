#include<iostream>
using namespace std;

int main(){

int a,b,c;

cout<<"\nEnter the 1st no. : ";
cin>>a;

cout<<"\nEnter the 2nd no. : ";
cin>>b;

cout<<"\nEnter the 3rd no. : ";
cin>>c;

if(a>b){
    if(a>c){
        cout<<"\n\n1st no. is the greatest : "<<a<<endl;
    }
    else{
        cout<<"\n\n3rd no. is the greatest : "<<c<<endl;
    }

}
else{
    if(b>c){
        cout<<"\n\n2nd no. is the graetest : "<<b<<endl;
    }
    else{
        cout<<"\n\n3rd no. is the greatest : "<<c<<endl;
        }
        
    }


    return 0;
}
