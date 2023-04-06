#include<iostream>                                   // Type conversion --> class to class using casting operator
using namespace std;

class Item {

    int a,b;

    public:

    void display() {
        cout<<"\na = "<<a<<" b = "<<b;
    }

    void setData(int x, int y){               //for using casting operator
        a=x;b=y;
    }
    
};

class Product {

    int m,n;

    public:

    void setData(int x, int y) {
        m = x;
        n = y;
    }

    operator Item(){

        Item temp;

        temp.setData(m,n);
        return(temp);
    }
};

int main() {

    Item i1;                                 
    Product p1;

    p1.setData(3,4);

    i1 = p1;
    i1.display();

    return 0;
}