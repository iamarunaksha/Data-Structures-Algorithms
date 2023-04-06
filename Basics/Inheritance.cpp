#include<iostream>                                          //Constructors & Destructors in Inheritance
using namespace std;

class A {

    int a;

    public:

    A(int k) {
        a = k;
    }

    void show_data() {

        cout<<"\nValue of a = "<<a;
    }

};

class B: public A {

    int b;

    public:

    B(int x, int y) : A(x) {

        b = y;
    }

    void Display() {

        show_data();

        cout<<"\nValue of b = "<<b;
    }

    ~B() {

    }

};

int main() {

    B obj(2,3);
    obj.Display();

    return 0;
}