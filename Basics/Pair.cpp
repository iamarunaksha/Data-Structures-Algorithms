#include<iostream>                                       //STL containers
#include<tuple>
#include<list>
#include<vector>
using namespace std;

int main() {

    pair <string, int> p1;
    p1 = make_pair("Raja",7);
    cout<<p1.first<<endl;
    cout<<get<1>(p1)<<endl;;

    tuple <string,int,int> t1;                          // 3 or more tha 3 data types can be there in a tuple
    t1 = make_tuple("India", 185, 1);
    cout<<get<0>(t1)<<endl;
    //cout<<t1.first<<endl; ---> throws error

    list <string> l1 {"India", "Japan", "Pakistan", "China"};
    l1.push_back("Burma");
    l1.push_front("Russia");

    list <int> l2 {11, 22, 33, 5, 1, 77, 44, 88, 21, 5};
    list <int> :: iterator pt = l2.begin();

    while(pt != l2.end()) {
        cout<<*pt<<" ";
        pt++;
    }

    cout<<"\n";

    l2.sort();
    l2.remove(5);
    l2.remove(100);
    //l2.clear(); ---> used to clear the entire list
    
    for (auto it = l2.begin(); it != l2.end(); it++)
        cout <<*it<<" ";

    cout<<"\n";

    for (auto it = l1.begin(); it != l1.end(); it++)
        cout <<*it<<" ";

    cout<<"\n";

    vector <int> v1(5,1);                     // (5) ---> capacity of vector, initializing all elements with 1. [] ---> subscript operator applies on vectors as well
    cout<<v1.capacity()<<endl;               // capacity ---> total no. of memory blocks. || size ---> total no. of elements in the vector

    for(int i=0; i<v1.size(); i++)
        cout<<v1[i]<<" ";

    return 0;
}