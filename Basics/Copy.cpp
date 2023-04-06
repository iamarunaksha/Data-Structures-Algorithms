#include<iostream>
using namespace std;

class A {

    int a,b;
    
    //int *p;                                       // for deep copy --> Creating an object by copying data of another object along with values of memory resources residing outside the object but handled by the object.

    public :

    /*A() {                                         // for deep copy
        p = new int;
    }
    */
    
    void setData(int x, int y) {                   //void setData(int x, int y, int z ) { ---> for deep copy
        a = x;
        b = y;
    
      // *p = z;                                  // *p denotes the memory block it is pointing towards. This memory block is outside the object created for A
    }

    void display() {
        cout<<"\na = "<<a<<", b = "<<b;
    }

    /* A(A &q) {                                  // shallow copy, copy constructor created by default
        a = q.a;
        b = q.b;

      //p = q.p;
    }
    */

    /* A(A &q) {                                  // deep copy, programmer has to code
        a = q.a;
        b = q.b;

      *p = new int;
      *p = *(q.p);
    }
    */

    /*~A() {
        delete p;
    }
    */

};

int main() {

    A a1,a2;

    a1.setData(3,4);
    a2 = a1;                                    //Shallow Copy, Implicit Copy assignment operator is called

    A a3=a1;                                    //Copy(default) constructor is clled

    a2.display();

    return 0;
}