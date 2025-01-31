#include<iostream>                                                  //Calculate no. of 1 bits for any decimal no.
using namespace std;

int main() {

    int num;
    cout<<"\nEnter any no. : ";
    cin>>num;

    int ans = 0;                              

    while(num!=0) {                                      
        if(num&1) {
            ans++;
        }
        num = num >> 1;
    }

    cout<<"\nThe no. of 1 bits = "<<ans;
    cout<<"\n"<<endl;

    return 0;
}