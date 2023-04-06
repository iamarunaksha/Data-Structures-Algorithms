#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector<int> nums = {1,5,7,6};

    cout<<"\nThe required sub-arrays are : "<<endl<<endl;
    
    
    for(int i=0; i<nums.size(); i++) {
        
        for(int j=i; j<nums.size(); j++) {

            for(int k=i; k<=j; k++) {
                cout<<nums[k]<<" ";
            }
            cout<<endl;
            }
        cout<<endl;
        }

    return 0;
}