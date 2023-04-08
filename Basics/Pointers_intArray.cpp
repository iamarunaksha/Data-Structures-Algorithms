#include<iostream>
using namespace std;

int main () {
    
    /*
    int arr[10] = {23, 122, 41, 67};                                       // https://www.codingninjas.com/codestudio/guided-paths/pointers --> Refer to this website & solve the contest for more clarity

    cout <<"Address of first memory block is --> " << arr << endl;
    cout << arr[0] << endl;
    cout <<"Address of first memory block is " << &arr[0] << endl;
    
    cout << "Value at arr " << *arr << endl;                          // 23 
    cout << "Value at *arr + 1 " << *arr + 1 << endl;                //  24
    cout << "Value at 8(arr) + 1 " << *(arr) + 1 << endl;           //   24
    
    cout << "Value at *(arr + 1) " << *(arr + 1) << endl;         //     122
    cout << "Value at arr[2] " << arr[2] << endl;                //      41
    cout << "Value at *(arr + 2) " << *(arr + 2) << endl;       //       41
    
    int i = 3;
    cout << i[arr] << endl;       // 67 = arr[3]
    
    int temp[10] = {1,2};
    cout << "Size of temp --> " << sizeof(temp) << endl;               // 40
    cout << "Size of *temp -->  " <<  sizeof(*temp) << endl;          //  4
    cout << "Size of &temp --> " <<  sizeof(&temp) << endl;          //   8
    
    int *ptr = &temp[0];
    cout << "Size of ptr --> " << sizeof(ptr) << endl;            // 8
    cout << "Size of *ptr --> " << sizeof(*ptr) << endl;         //  4
    cout << "Size of &ptr --> " << sizeof(&ptr) << endl;        //   8
    
    int a[20] = {1,2,3,5};
    cout << " ->" << &a[0] << endl;       // Address of 1st memory block of a
    cout << &a << endl;                  // Same as above
    cout << a << endl;                  // Same as above
    
    int *p = &a[0];
    cout << "Address of p -> "<< p << endl;   // Address of a
    cout << *p << endl;   // 1
    cout << "Address of p -> " << &p << endl; // Address of p
    */

    int arr[10];

    //arr = arr+1;           // This line would throw an ERROR

    int *ptr = &arr[0];
    
    cout << ptr << endl;    // Address of arr
    
    ptr = ptr + 1;
    
    cout << ptr << endl;    // Address of arr + 1 = arr[1]
    cout << &ptr << endl;  //  Address of ptr

    return  0;
}
