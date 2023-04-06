#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter no. of rows : ";
    cin>>n;

    int row = 1;
    while(row <= n) {

        //space print
        int space = 1;
        while(space<row) {
            cout<<" ";
            space = space + 1;
        }

        //element print
        int col = 1;
        int temp = row;
        while(col <= n - row + 1) {
            cout<<temp;
            temp+=1;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}