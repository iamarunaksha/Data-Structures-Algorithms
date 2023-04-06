#include <iostream>                                              //Recursion ~ Parameterised & Functional
using namespace std;

void parameterisedSum(int i, int sum) {
    
    if(i<1) {
        cout<<sum;
        return;
    }
    parameterisedSum(i-1,sum+i);
}

void parameterisedFact(int i, int fact) {
    
    if(i<1) {
        cout<<fact;
        return;
    }
    parameterisedFact(i-1,fact*i);
}

int functionalSum(int n) {
    
    if(n==0)
        return 0;
    
    return(n+functionalSum(n-1));
}

int functionalFact(int n) {
    
    if(n==0)
        return 1;
    
    return(n*functionalFact(n-1));
}

//2 pointer approach
void reverseArray(int arr[], int l, int r) {
    
    if(l>=r)
        return;
        
    swap(arr[l],arr[r]);
    reverseArray(arr,l+1,r-1);
}

//using only 1 pointer
void arrayReverse(int arr[], int size, int i) {
    
    if(i>=size/2)
        return;
        
    swap(arr[i],arr[size-i-1]);
    arrayReverse(arr,size,i+1);
}

bool checkPalindrome(int i, string s) {
    
    if(i >= s.size()/2) return true;
    
    if(s[i] != s[s.size()-i-1]) return false;
    
    return checkPalindrome(i+1,s);
}

void printArray(int arr[], int size) {
    
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

int fibonacci(int n) {

    if(n<=1) return n;

    int last = fibonacci(n-1);
    int s_last = fibonacci(n-2);

    return last + s_last;
}

int main()
{
    int n;
    cin>>n;
    
    //parameterisedSum(n,0);
    
    // int ans = functionalSum(n);
    // cout<<ans;
    
    // int ans = functionalFact(n);
    // cout<<ans;
    
    //parameterisedFact(n,1);

    // int size = 6;
    // int arr[size] = {1,2,3,4,5,6};
    
    // reverseArray(arr,0,size-1);
    // arrayReverse(arr,size,0);
    //printArray(arr,size);
    
    // string str = "raja";
    // cout<<checkPalindrome(0,str);

    //cout<<fibonacci(n);

    return 0;
}
