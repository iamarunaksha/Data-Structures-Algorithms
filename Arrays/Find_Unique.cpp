#include<iostream>
using namespace std;

int FindUnique(int arr[], int size)
{
    int ans=0;
        
        for(int i = 0; i<size; i++) {
            ans ^= arr[i];                    //XOR op.
        }
        return ans;
}

int main() {
    
    int size;
    cout<<"\nEnter the size(length) of the array (N=2m+1) (odd) : ";
    cin>>size;

    int num[100];
    cout<<"\nEnter the elements of the array : "<<endl;

    for(int i=0; i<size; i++) {                                     //input of array elements
        cin>>num[i];
    }

    cout<<"\nThe unique element in the array is : "<<FindUnique(num,size);

    cout<<"\n"<<endl;

    return 0;

}