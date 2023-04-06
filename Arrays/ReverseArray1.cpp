#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v) {

    int s = 0, e  = v.size() - 1;

    while(s<=e) {
        swap(v[s], v[e]);
        s++;
        e--;
    }
    return v;
}

void print(vector<int> v) {

    for(int i=0; i<v.size(); i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int n;
    cout<<"\nEnter the size of the array : ";
    cin>>n;

    vector<int> v(n);
    cout<<"\nEnter the elements of the array :"<<endl;

    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    vector<int> ans = reverse(v);                               //storing reversed array into ans<vector>

    cout<<"\nThe reversed array is : ";
    print(ans);
    
    cout<<endl;

    return 0;
}