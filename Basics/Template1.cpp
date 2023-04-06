#include<iostream>
using namespace std;

/*template <class X>                          // function template
X big(X a, X b) {                            //X is the data type

    if (a>b)
        return(a);

    else
        return(b);
}*/

template <class X, class Y> auto big(X a, Y b) {                 // if-else block deosen't work here    

    return (a>b)?a:b;                                           //?: operator --> condition ? value_if_true : value_if_false
}

int main() {

    cout<<"\nGreater of the 2 no.s is : "<<big(5,6);
    cout<<"\nGreater of the 2 no.s is : "<<big(5.8,9.6);
    cout<<"\nGreater of the 2 no.s is : "<<big(4,10.8);

    return 0;
}