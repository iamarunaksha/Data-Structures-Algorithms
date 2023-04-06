#include<iostream>
using namespace std;

class Account {

    int balance;
    static float roi;                                   // static member variable, a.k.a Class variable. They don't belong to an object but the entire class
                                                       // only 1 copy of static member variable for the entire class
    public :
    void set_balance(int b) {
        balance = b;
    }

    static void set_roi(float r) {                      //Static member function, a.k.a Class function. They can only access static members of the class
        roi = r;
    }

    static void display() {
        cout<<"\nThe rate of interest is : "<<roi;
    }
};

float Account :: roi;                               // w/out this line roi variable won't be created. Defining roi

int main() {

    Account :: set_roi(8.1);                        // one can call static member function w/out creating an object

    Account :: display();

    return 0;
}