#include<iostream>
using namespace std;

int main() {

    int num;
    cout<<"\nEnter any integer : ";
    cin>>num;

    int n = num , pdt = 1 , sum = 0;

    while(n) {
        
        pdt*=n%10;
        sum+=n%10;
        n/=10;
    }

    cout<<"\n(Product - Sum) of the digits of the ineger "<<num<<" is = "<<(pdt-sum);
    cout<<"\n"<<endl;

    return 0;
}