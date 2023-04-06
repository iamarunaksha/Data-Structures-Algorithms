#include<iostream>
#include<fstream>
using namespace std;

int main() {

    ofstream f_out;
    f_out.open("file.txt");
    f_out<<"Hello!";
    f_out.close();

    ifstream f_in;
    f_in.open("file.txt");
    
    /*char ch[10];
    f_in.getline(ch,10);
    cout<<ch;
    */

    
    char ch;

    while(!f_in.eof()) {                                            // while(f_in>>ch) {    ---> better practice
        
        cout<<ch;                                                  //    cout<<ch;
        f_in>>ch;                                                 // }
    }
    
    f_in.close();

    return 0;
}