#include <iostream>
using namespace std;

int main()
{
    string s;
    cout<<"\nEnter the string : ";
    cin>>s;
    
    int query;
    cout<<"\nEnter the no. of query : ";
    cin>>query;
    
    //pre-compute or hashing
    //int hash[26] = {0};                                     //for lowercase or uppercase only (1 at a time)
    int hash[256] = {0};                                      // it takes all characters w/out uppercase or lowercase constraint
    
    for(int i=0; i<s.size(); i++) {
        hash[s[i]]++;                                   //for lowercase ---> s[i] - 'a'.  for uppercase ---> s[i] - 'A'
    }
    
    while(query--) {
        
        char c_query;
        cout<<"\nEnter the query input : ";
        cin>>c_query;
        
        cout<<endl;
        
        //fetch
        cout<<c_query<<" appears "<<hash[c_query]<<" times"<<endl;      //for lowercase ---> hash[c_query-'a']
        
        cout<<endl;
    }

    return 0;
}
