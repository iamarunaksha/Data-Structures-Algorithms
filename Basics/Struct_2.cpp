#include<iostream>
#include<cstring>
using namespace std;

struct book {                                   //using functions as member functions within the structure book

    //private:                                  // these 3 variables cannot be accessed from outside structure

    int book_id;                    
    char book_name[100];                       // in 'structure' access specifier is public by default, whereas in 'classes' its private by default
    float price; 

   //public: 

    void input() {
    
    cout<<"\n\nEnter book_id : ";
    cin>>book_id;

    cout<<"\nEnter book_name : ";
    cin.ignore();                                   //clear buffer before taking new i/p, to consume new-line produced by enter after book_id
    cin.getline(book_name,sizeof(book_name));

    cout<<"\nPrice : ";
    cin>>price;
    } 

    void display() {
    
    cout<<"\nBook ID : "<<book_id;
    cout<<"\nBook Name : "<<book_name;
    cout<<"\nPrice : "<<price;
    cout<<endl;
    } 

    };

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
    b3.input();
    b3.display();

    return 0;
}