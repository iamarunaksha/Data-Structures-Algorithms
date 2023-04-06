#include<iostream>                                                          //class template
using namespace std;

template<class X> class ArrayList {

    struct ControlBlock {                                                   //if we use class instead of struct, then it becomes inaccessible for other instance members

        int capacity;
        X *arr_ptr;
    };

    ControlBlock *s;

    public:

    ArrayList(int capacity){                                        //Constructor

        s = new ControlBlock;           //The new operator is an operator which denotes a request for memory allocation. If sufficient memory is available, new operator initializes the memory and returns the address of the newly allocated and initialized memory to the pointer variable.
        s->capacity=capacity;
        s->arr_ptr = new X[s->capacity];    //using obj(capacity), an X[capacity] array is created.
    } 

    void add_Element(int index, X data) {

        if(index>=0 && index<=s->capacity-1)
            s->arr_ptr[index]=data;
        else
            cout<<"\nArray index is not valid";
    }

    void view_Element(int index, X &data) {

        if(index>=0 && index<= s->capacity-1) {
            data = s->arr_ptr[index];
            cout<<"\nElement at "<<index<<" = "<<data;
            cout<<endl;
        }    
        else
            cout<<"\nArray index is not valid";
    }

    void viewList() {

        for(int i=0; i<s->capacity; i++) {
            cout<<" "<<s->arr_ptr[i];
        }
    }
};

int main() {

    double data;
    
    ArrayList <double> list1(4);
    list1.add_Element(0,32.5);
    list1.add_Element(1,15.8);
    list1.add_Element(2,20.7);
    list1.add_Element(3,10);

    list1.view_Element(0,data);

    list1.viewList();

    return 0;
}