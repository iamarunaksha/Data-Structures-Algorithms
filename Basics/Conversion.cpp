#include<iostream>                                       // Type conversion --> class to class using constructor
using namespace std;

class Product {

    int m,n;

    public:

    void setData(int x, int y) {
        m = x;
        n = y;
    }

    int getM() {
        return(m);
    }

    int getN() {
        return(n);
    }
};

class Item {

    int a,b;

    public:

    void display() {
        cout<<"\na = "<<a<<" b = "<<b;
    }

    Item() {}                                   //default constructor
    
    Item(Product p) {                          //Constructor for conversion

        a = p.getM();
        b = p.getN();
    }
};

int main() {

    Item i1;                                 //w/out default constructor being written, this line is invalid
    Product p1;

    p1.setData(3,4);

    i1 = p1;
    i1.display();

    return 0;
}