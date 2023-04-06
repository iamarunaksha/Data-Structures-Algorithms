#include<iostream>
#include<cstring>
using namespace std;

struct book {                    //Structure is a collection of dissimilar elements.        

    int book_id;                    //It's a way to gp variables. 
    char book_name[100];            //Used to create a new data type
    float price;    
    };  

book input() {

    book b;

    cout<<"\n\nEnter book_id : ";
    cin>>b.book_id;

    cout<<"\nEnter book_name : ";
    cin.ignore();                                   //clear buffer before taking new i/p, to consume new-line produced by enter after book_id
    cin.getline(b.book_name,sizeof(b.book_name));

    cout<<"\nPrice : ";
    cin>>b.price;

    return(b);
} 

void display(book b) {

    cout<<"\nBook ID : "<<b.book_id;
    cout<<"\nBook Name : "<<b.book_name;
    cout<<"\nPrice : "<<b.price;
}

int main() {                                

    struct book b1 = {1, "Patience by Arunaksha", 499};             //in C its mandatory to declare 'struct' keyword before definining b1
    cout<<"\nBook_id : "<<b1.book_id;
    cout<<"\nBook_Name : "<<b1.book_name;
    cout<<"\nPrice : "<<b1.price;

    book b2;                                // in C++, its not mandatory to declare struct keyword before individual items
    b2.book_id = 101;
    strcpy(b2.book_name,"Epic Shit");    
    b2.price = 150;
    cout<<"\n\nBook_id : "<<b2.book_id;
    cout<<"\nBook_Name : "<<b2.book_name;
    cout<<"\nPrice : "<<b2.price;

    book b3;
    b3 = input();
    display(b3);

    return 0;
}