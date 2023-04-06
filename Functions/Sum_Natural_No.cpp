#include<iostream>
using namespace std;

int sum(int limit) {

    int ans = 0;

    for(int i=1; i<=limit; i++)
    ans+=i;

    return ans;
}

int main() {

    int n;
    cout<<"Enter the no. upto which sum is desired : ";
    cin>>n;

    cout<<"\nSum of first "<<n<<" natural no.s : "<<sum(n);
    cout<<"\n"<<endl;

    return 0;
}