#include<iostream>                                     //Max occurrence of a character in a string
using namespace std;

char getMaxOccChr(string n) {

    int arr[26] = {0};

    for(int i=0; i<n.length(); i++) {                 //for creating arr of count for each character(alphabets)

        char ch = n[i];

        int res = 0;

        if(ch>='a' && ch<='z') {                        //for lowercase
            res = ch - 'a';
        }
        else {                                         //for uppercase
            res = ch - 'A';
        }

        arr[res]++;
    }

    int maxi = -1, ans = 0;

    for(int i=0; i<26; i++) {                       //finding max occurring character
        if(arr[i] > maxi) {
            ans = i;                               //finds ith index no. in arr which has max occurrence & stores it in ans.
            maxi = arr[i];
    }
}

    char finalAns = 'a' + ans;                     //for returning char in the end
    return finalAns;

}


int main() {

    string s;
    cout<<"\nEnter string : ";
    cin>>s;

    cout<<endl<<getMaxOccChr(s)<<" has max occurrence."<<endl;


    return 0;
}