#include <iostream>                           // Hashing is useful to handle multiple input queries
using namespace std;

//int arr[size];                             // globally size can be 10^7 or 1e7 (for int), fir bool array size globally can be 10^8

int main()
{
    int n;
    cout<<"\nEnter the no. of elements in the array : ";
    cin>>n;
    
    int arr[100];                           //for bool array inside main, max size is 10^7
    cout<<"\nEnter the elements of the array :\n";
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    
    //pre-computing (hashing)
    int hash[13] = {0};                     //initialising the hash array with 0. Max array size that can be declared inside main is 10^6, anything above this throws segmentation fault
    
    for(int i=0; i<n; i++) {
        hash[arr[i]] += 1;
    }
    
    int query;
    cout<<"\nEnter the no. of query : ";
    cin>>query;
    
    while(query--) {
        
        int numQuery;
        cout<<"\nEnter the query input : ";
        cin>>numQuery;
        
        cout<<endl;
        
        //fetch
        cout<<numQuery<<" appears "<<hash[numQuery]<<" times"<<endl;
        
        cout<<endl;
    }
    
    return 0;
}
