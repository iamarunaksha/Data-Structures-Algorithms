#include<iostream>
using namespace std;

int main() //Loops (continue)
{
    
    cout<<"The no.s not divisible by 3 b/w 0-100 are : \n";

    for(int i = 0; i<=100; i++){
        
        if(i%3==0){
            continue;
        }
        cout<<i<<endl;
        }

        return 0;
}