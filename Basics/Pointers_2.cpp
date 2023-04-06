#include<iostream>
using namespace std;

class Box {

    int l,b,h;                                      // instance member variables

    public:

    void set_dimension(int x, int y, int z) {                           //instance member function, x, y, z are local variables
        this->l = x;
        this->b = y;
        this->h = z;
    }

    void show_dimension() {
        cout<<"\nl = "<<l<<" b = "<<b<<" h = "<<h;
    }

};

int main() {

    Box *p,smallbox;
    p = &smallbox;                              //*p is object pointer ---> pointer which stores the address of an object is called an object pointer

    p->set_dimension(10,12,20);
    p->show_dimension(); 

    return 0;
}