#include<iostream>
using namespace std;

int gcd(int a, int b) {

    if(a==0)
        return b;

    if(b==0)
        return a;

    while(a != b) {

        if(a>b)
            a = a-b;
        
        else
            b = b-a;
    }

    return a;
}

int lcm(int a, int b) {
    
    return a*b/gcd(a,b);
}

int main() {
    
    int a,b;
    cout << "\nEnter the values of a and b : ";
    cin >> a >> b;

    int ans = gcd(a,b);

    int res = lcm(a,b);

    cout << "\nThe Greatest Common Divisor of " << a << " & " << b << " is : " << ans << endl;

    cout << "\nThe Least Common Multiple of " << a << " & " << b << " is : " << res << endl;

    return 0;
}