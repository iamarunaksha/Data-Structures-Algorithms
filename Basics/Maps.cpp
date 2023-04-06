#include<iostream>
#include<map>
using namespace std;

int main() {

    map<int,string> customer;

    customer[1] = "Raja";
    customer[2] = "Rimjhim";
    customer.insert(pair<int,string>(3,"Babli"));

    for(auto it = customer.begin(); it != customer.end(); it++) 
        cout<< it->second <<" ";                                        // second --> refers to values, || first ---> keys
    

    map<string,int> marks { {"Angana",80}, {"Babli",100}, {"Raja",90}, {"Rimi",95} };

    return 0;
}