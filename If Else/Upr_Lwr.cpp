#include <iostream>
using namespace std;

int main(){

   char ch;
   cout<<"\nInput a character : ";
   cin>>ch;

   if(ch>= 'A' && ch<= 'Z'){
    cout<<"\nUppercase"<<endl;
   }
   else if(ch>= 'a' && ch<= 'z'){
    cout<<"\nLowercase"<<endl;
   }
   else {
    cout<<"\nDigits"<<endl;
   }

    cout<<endl;

    return 0;
}