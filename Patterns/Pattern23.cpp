#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"\nEnter no. of rows : ";
    cin>>n;

    int row = 1;
    int temp = 1;
    while(row <= n) {

        //space print
        int space = 1;
        while(space<=n-row) {
            cout<<"  ";
            space = space + 1;
        }

        //element print
        int col = 1;
        while(col <= row ) {
            cout<<temp<<" ";
            temp+=1;
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}