#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    
    char ch[6] = "abcde";         // Size of array should be always atleast 1 more for char arrays because of \0 null character at the end.

    cout << arr << endl;         // Print the address of arr
    //attention here
    cout << ch << endl;         // Prints the entire string abcde
    
    char *c = &ch[0];
    //Pointers also prints entire string, since at c address of ch is stored which when printed through cout returns the entire string bcoz of diff implementation of cout for char arrays
    cout << c << endl;
    
    //char *d = "abc"           // This is a very bad practice as at first a temp memory block is created where abc is sored & address of that temp. memory is stored in the pointer d. That might be a read only memory or something else, so its never a good practice to declare char pointers this way as it points a temp memory block.

    char temp = 'z';
    char *p = &temp;         

    cout << p << endl;        // Prints unwanted charters till iterator finds a \0 character in the end

    return 0;
}
