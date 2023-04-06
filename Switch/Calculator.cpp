#include<iostream>
using namespace std;

int main()
{
    
    float n1,n2;
    cout<<"\nEnter the 1st no. : ";
    cin>>n1;

    cout<<"\nEnter the 2nd no. : ";
    cin>>n2;

    char op;
    cout<<"\nEnter choice of operator : ";
    cin>>op;

    switch(op)
    {

    case '+' :
        cout<<"\nSum of 2 no.s is : "<<n1+n2<<endl;
        break;

        case '-' :
        cout<<"\nDifference of 2 no.s is : "<<n1-n2<<endl;
        break;

        case '*' :
        cout<<"\nMultiplication of 2 no.s is : "<<n1*n2<<endl;
        break;

        case '/' :
        cout<<"\nDivision of 2 no.s is : "<<n1/n2<<endl;
        break;

        default:
        cout<<"Operator not recognised";
        break;

    }
    
    return 0;
}