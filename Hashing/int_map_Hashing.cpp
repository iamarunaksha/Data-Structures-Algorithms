#include <iostream> 
#include<map>                          
using namespace std;

int main()
{
    int n;
    cout<<"\nEnter the no. of elements in the array : ";
    cin>>n;
    
    int arr[100];                           
    cout<<"\nEnter the elements of the array :\n";
    //map<int,int> mpp;                     //pre-computing can be done while taking the array i/p only

    for(int i=0; i<n; i++) {
        cin>>arr[i];
        //mpp[arr[i]]++;
    }
    
    //pre-computing (hashing)
    map<int,int> mpp;
    
    for(int i=0; i<n; i++) {
        mpp[arr[i]]++;
    }

    //iterate in a map
    /*for(auto it : mpp) {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    */
    
    int query;
    cout<<"\nEnter the no. of query : ";
    cin>>query;
    
    while(query--) {
        
        int numQuery;
        cout<<"\nEnter the query input : ";
        cin>>numQuery;
        
        cout<<endl;
        
        //fetch
        cout<<numQuery<<" appears "<<mpp[numQuery]<<" times"<<endl;
        
        cout<<endl;
    }
    
    return 0;
}
