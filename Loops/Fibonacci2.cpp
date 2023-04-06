#include <iostream>
using namespace std;

int main() 
{
    int n, t1 = 0, t2 = 1, nextTerm = 0;                      //using for loop

    cout <<"\nEnter the number of terms : ";
    cin >> n;

    cout <<"\nFibonacci Series : ";

    for (int i = 1; i <= n; ++i) {
        // Prints the first two terms.
        if(i == 1) {
            cout << t1 << " ";
            continue;
        }
        if(i == 2) {
            cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << " ";
    }
   
    cout<<"\n"<<endl;

    return 0;
}