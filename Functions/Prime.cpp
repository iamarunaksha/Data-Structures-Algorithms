#include<iostream>
using namespace std;

// 0 -> Not a Prime no.
// 1 -> Prime no.

bool isPrime(int num) {
   
   for(int i = 2; i < num; i++){
       if(num % i == 0) {
          return 0;
        }
   }
   return 1;
}

int main() {
   
   int n ;
   cout<<"\nEnter the no. that you want to check for prime no. : ";
   cin >> n;
   cout<<endl;

   if(isPrime(n)) {
        cout<<n<<" is a Prime number"<<endl;
   }
   else{
       cout<<n<<" is not a prime number"<<endl;
   }

cout<<endl;

   return 0;
}