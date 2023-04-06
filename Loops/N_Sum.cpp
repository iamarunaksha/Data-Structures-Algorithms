#include <iostream>
using namespace std;

int main() {
    
    cout<<"\nEnter the no. of numbers you want to add : ";
    int n;
    cin>>n;
    
    int arr[n];
    
    for(int i=0; i<n; i++) {
        
        cout<<"\nEnter no. "<<i+1<<" : ";
        cin>>arr[i];
    }
    
    int sum = 0;
    
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    
    cout<<"\nSum of "<<n<<" no.s are : "<<sum;
    
    return 0;
}