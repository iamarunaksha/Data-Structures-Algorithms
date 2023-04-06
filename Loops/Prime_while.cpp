#include<iostream>                                      //Using while loop
using namespace std;

int main() {
    
    int n;
    cout<<"\nEnter no. that you want to check : ";
    cin>>n;

    int i=2;

    while(i<n){

        if(n%i==0){
            cout<<"\nThe given no. "<<n<<" is not prime.";
            return 0;
        }
       
        i+=1;

    }

    cout<<"\nThe given no. "<<n<<" is prime.";
    cout<<"\n"<<endl;
    
    return 0;
}