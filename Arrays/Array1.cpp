#include<iostream>
using namespace std;

int main() {

    /*int arr[1000] = { [0 ... 1000] = 3 };   ---> for gcc compilers only                            
                                                         // arr[]={3,3,3,3,3} but for 5 positions only */
    
    
    
    int arr[1000];
    fill_n(arr,1000,3);                                   //using fill_n function
    
    cout<<"Elements of the array is : "<<endl;
    
    for(int i=0; i<10; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}