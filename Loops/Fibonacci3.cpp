#include <iostream>
using namespace std;

int main() {
    int t1 = 0, t2 = 1, nextTerm = 0, n;                        //Series upto a certain no. (more than 3)

    cout <<"\nEnter the no. upto which the series is to be displayed : ";
    cin >> n;

    // displays the first two terms which is always 0 and 1
    cout <<"\nFibonacci Series : " << t1 << " " << t2 << " ";

    nextTerm = t1 + t2;

    while(nextTerm <= n) {                                     //using while loop
        
        cout << nextTerm << " ";
        
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    cout<<"\n"<<endl;

    return 0;
}