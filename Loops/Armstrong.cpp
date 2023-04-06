#include<iostream>                                       //Armstrong No.  
#include<math.h>                                      //Important
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the no. : ";
    cin>>n;

    int sum=0;
    int originaln=n;

    while(n>0){
        int lastdigit= n%10;            
        sum+= float(pow(lastdigit,3));          // pow() returns a double value || round() returns the equivalent int
        n= n/10;                               // removing last digit from the orignal number
    }

    if(sum==originaln){
        cout<<"\nThe no. "<<originaln<<" is an Armstrong no. "<<endl; 
    }
    else{
        cout<<"\nThe no. "<<originaln<<" is not an Armstrong no. "<<endl;
    }

    return 0;
}