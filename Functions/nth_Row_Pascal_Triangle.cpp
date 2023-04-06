#include<iostream>
using namespace std;

void printRow(int n) {                                  // T.C --> O(n)    S.C --> O(1)

    int ans = 1;

    cout<<ans<<" ";

    for(int i=1; i<n; i++) {

        ans *= (n-i);
        
        ans /= i;

        cout<<ans<<" ";
    }
}

int main() {

    int n;

    cout<<"\nEnter the row no. : ";
    cin>>n;

    printRow(n);

    return 0;
}