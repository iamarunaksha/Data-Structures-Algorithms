#include<iostream>                                              //Class,Constructor, Operator overloading, Type Conversion(primitive to class & vice versa)
using namespace std;

class Complex {

    int a,b;                                              // instance member variable, a.k.a attributes, data members, fields, properties
    //const int p;
    //int &q;

    public: 

    //void set_data(int, int);                          // function declaration within the class
    
    void set_data(int x, int y) {                      // instance member function, a.k.a methods, procedures, actions, operations, services
        a = x;
        b = y;
    }

    /* Complex() : p(4),q(n),a(5),b(6) {                       // Initializer list --> used to initialize deata members of a class
                                                         // Const members, reference variables have to be initialized with a initializer list
    }
   */


    /* Complex(int x, int y) {                      // Parameterized constructor, used to initialize an object.
        a = x;
        b = y;
    }
    */

     /*Complex() {                                 // Default constructor, it is created everytime an object of the class is created

    }
    */
                                                // Default & copy constructors are created by default by the compiler 

    /* Complex(Complex &c)                        //Copy Constructor. If (Complex c) is passed then there will be an error due to recursion. 
        a = c.a;
        b = c.b;
  */

     /*Complex(int f) {                           //Type casting --> Primitive (int) to class (Complex) type
        a = f;                                  // default constructor has to coded by the programmer, so that an object can be created w/out passing an arg.
        b = 0;
    }
    */

    /*operator int() {                            //Type casting --> Class to primitive
        
        return (a);
    }
    */
    
    /* ~Complex() {                             //Destructor. It can't be static. Since no arguments can be passed, so there's no overloading

    }
    */

    void display() {
        cout<<"\nSum of complex no.s are : ";
        cout<<a<<" + "<<b<<"i";
        cout<<"\na = "<<a<<", "<<"b = "<<b<<"i";
        cout<<endl;
    }

    /* Complex add(Complex c) {

        Complex temp;

        temp.a = a + c.a;                               // a belongs to c1.a since its calling the function & c.a belongs to c2.a since its being passed as an argument
        temp.b = b + c.b;
        return(temp);
    } */

    Complex operator+(Complex c) {                     //Operator overloading - operator loaded with multiple jobs. Way to implement Compile time polymorphism
                                                      // sizeof() & ?: operators cannot be overloaded.
        Complex temp;

        temp.a = a + c.a;                               
        temp.b = b + c.b;
        return(temp);
    }
};

/*void Complex :: set_data(int x, int y) {             //function creation outside the class, handy when its a lengthy function
        a = x;
        b = y;
}*/

int main() {

    Complex c1,c2,c_sum,c3;                                 //c1,c2 is an object
    
    /*int m = 6;                                        // m is intialized into q using the initializer list.
    Complex c6(m);
    */

    c1.set_data(3,4);
    c2.set_data(5,6);

    //Complex c3(c1);                                   // It would call copy constructor.

    //c_sum = c1.add(c2);
    c_sum = c1 + c2;                                   // Using operator+ function
    c_sum.display();
    
                                                      //Type conversion --> primitive to class type (Constructor)
    /*int g = 7;
    c3 = g;                                          // not valid --> c3.Complex(g), but an easy way to understand
    c3.display();
    */

    /*int l;                                         // Type conversion --> Class type (Complex) to primitive type (int) using casting 'operator' keyword
    l = c1;                                         // not valid --> l = c1.operator int(); 
    cout<<"l = "<<l;
    */

    return 0;
}