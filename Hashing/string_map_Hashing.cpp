#include <iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    cout<<"\nEnter the string : ";
    cin>>s;
    
    int query;
    cout<<"\nEnter the no. of query : ";
    cin>>query;
    
    map<char,int> mpp;

    for(int i=0; i<s.size(); i++) {
        mpp[s[i]]++;
    }                                   
    
    while(query--) {
        
        char c_query;
        cout<<"\nEnter the query input : ";
        cin>>c_query;
        
        cout<<endl;
        
        //fetch
        cout<<c_query<<" appears "<<mpp[c_query]<<" times"<<endl; 
        
        cout<<endl;
    }

    return 0;
}
