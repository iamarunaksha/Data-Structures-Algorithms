#include <iostream>
using namespace std;

void printName(int i,int n) {
    
    if(i>n-1) {
        return;
    }
    
    else {
      
        cout<<"Raja"<<endl;
        i++;
        printName(i,5); 
    }
    
}
void countNum(int i, int n) {
    
    if(i>n)
        return;
        
    cout<<i<<endl;
    i++;
    countNum(i,n);
}
void reverseCountNum(int n) {
    
    if(n<1)
        return;
        
    cout<<n<<endl;
    n--;
    reverseCountNum(n);
}

int main()
{
    int n;
    cout<<"\nEnter the no. of times you want to print : ";
    cin>>n;
    cout<<endl;
    
    //printName(0,5);
    countNum(1,n);
    //reverseCountNum(n);

    return 0;
}