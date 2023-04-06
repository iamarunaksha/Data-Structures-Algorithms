#include <iostream>                     //Sum of all the even no.s in a given range
using namespace std;

int main() {

    int u,l;

    cout<<"\nEnter the lower limit : ";
    cin>>l;
    
    cout<<"\nEnter the upper limit : ";
    cin>>u;

    int sum = 0;

    for (int i = l; i <= u; i++)
    {
        if(i%2==0){
            sum+= i;
        }
    }
    
    cout<<"\nSum of even no.s in the given range is : "<<sum;

    return 0;
}