#include<iostream>                                      //Its mandatory to have a class or enum for op. overloading
#include<conio.h>
using namespace std;

class Number {

    int x;

    public:

    void set_data(int a) {
    x = a;
    }

    void Display() {
        cout<<"x = "<<x<<" ";
    }

    Number operator++() {               //Pre-increment

        Number n;

        n.x = ++x;

        return(n);
    }

     Number operator++(int) {         //Post-increment, (int) arg. is passed so that function template doesn't remain the same

        Number n;

        n.x = x++;

        return(n);
    }
};


int main() {

    Number n1,n2;

    n1.set_data(3);
    n1.Display();

    n2 = ++n1;

    n1.Display();
    n2.Display();
    
    return 0;
}