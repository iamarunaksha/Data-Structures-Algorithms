#include<iostream>                                              //Friend function
using namespace std;

class Complex {

    int a,b;

    public: 
    
    void set_data(int x, int y) {                      // instance member function, a.k.a methods, procedures, actions, operations, services
        a = x;
        b = y;
    }

    void display() {
        cout<<"\nSum of complex no.s are : ";
        cout<<a<<" + "<<b<<"i";
        cout<<"\na = "<<a<<", "<<"b = "<<b<<"i";
        cout<<endl;
    }

    friend void sum(Complex);

    friend Complex operator+ (Complex, Complex);

    friend Complex operator-(Complex);

    friend istream& operator>> (istream&, Complex&);                //extraction operator for i/p, for i/p & or reference variable is used, since we have to store the i/p value in the memory address of the variable 

    friend ostream& operator<< (ostream&, Complex);             // insertion operator for o/p
};

void sum(Complex c) {                                   // friend func. is not a member function  of a class to which it's a friend. Has to be declared inside the class but defined outside.

    cout<<"Sum is : "<<(c.a + c.b);                    // it can access any member of the class but not directly. It can be friend to more than one class. It doesn't matter whether friend func. is declared under private or public since its not a member func.
}

Complex operator+ (Complex A, Complex B) {             // Operator overloading as a friend function

    Complex temp;

    temp.a = A.a + B.a;
    temp.b = A.b + B.b;

    return(temp);
}

Complex operator- (Complex X) {                         //Unary operator overloading

    Complex temp;

    temp.a = -X.a;
    temp.b = -X.b;

    return(temp);
}

istream& operator>>(istream &din, Complex &C) {

    cin>>C.a>>C.b;
    return(din);
}

ostream& operator<<(ostream &dout, Complex C) {

    cout<<"\na= "<<C.a<<", b= "<<C.b;
    return(cout);
}

class A {

    public:

    void fun() {                                          //Member function of 1 class & friend to another class

    }
};

class B {

    friend class A;                                     //All member functions of A are friend to B
    
    //friend void A:: fun();
};

int main() {

    Complex c1,c2,c3,c4,c5;
    c1.set_data(3,4);
    c2.set_data(5,6);

    c4 = -c2;                                       //c4 = operator-(c2);

    sum(c1);                                        // friend func. has no caller object.

    c3 = c1 + c2;
    c3.display();

    c4.display();

    cout<<"\nEnter the complex no. : ";             // Relatively tough to understand. To take i/p of complex no.s using cin 
    cin>>c5;

    cout<<"\nComplex no. is : ";
    cout<<c5;

    return 0;
}