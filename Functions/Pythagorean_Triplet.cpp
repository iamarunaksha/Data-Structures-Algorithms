#include<iostream>
using namespace std;

bool check(int p, int q, int r) {

    int a, b, c;

    a = max(p, max(q,r));                               //max function can have only 2 arguments in it for comparison

    if(a == p) {
        b = q;
        c = r;
    }

    else if(a == q) {
        b = p;
        c = r;
    }

    else {
        b = p;
        c = q;
    }

if(a*a == b*b + c*c) 
    return true;
else 
    return false;

}

int main() {

    int x,y,z;
    cout<<"\nEnter the 3 integers you wish to check for Pythagorean Triplet : ";
    cin>> x >> y >> z;

    if(check(x,y,z)) {
        cout<<"\nGiven three no.s : "<<x<<", "<<y<<", "<<z<<" are Pythagorean Triplets";
    }
    else {
        cout<<"\nGiven three no.s : "<<x<<", "<<y<<", "<<z<<" are not Pythagorean Triplets";
    }

    return 0;
}