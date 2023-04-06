#include<iostream>                                                      //for any array (sorted/unsorted)
#include<vector>                                                        //not optimised
using namespace std;

int main() {

    int size1;                                                          //1st array
    cout<<"\nEnter the size(length) of the 1st array : ";
    cin>>size1;

    int ar1[100];
    cout<<"\nEnter the elements of the 1st array : "<<endl;

    for(int i=0; i<size1; i++) {                                     //input of array elements
        cin>>ar1[i];
    }

    int size2;                                                          //2nd array
    cout<<"\nEnter the size(length) of the 2nd array : ";
    cin>>size2;

    int ar2[100];
    cout<<"\nEnter the elements of the 2nd array : "<<endl;

    for(int i=0; i<size2; i++) {                                     //input of array elements
        cin>>ar2[i];
    }
    
    cout<<"\nIntersection of the 2 array is : ";

    for(int i=0; i<size1; i++) {                                    
        int element = ar1[i];
        
        for(int j=0; j<size2; j++) {
            
            if(element == ar2[j]) {
            cout<<element<<" ";
            ar2[j]= -1;
            break;
        }
    }
}

    cout<<"\n"<<endl;
    
    return 0;
}