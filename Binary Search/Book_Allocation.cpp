#include <bits/stdc++.h>                                                    //Brute Force
using namespace std;

/*function to check if it is possible to allocate the books such that the
maximum number of pages assigned to any student is numPages*/
bool isPossible(int pages[], int n, int m, int numPages) {
    int cntStudents = 1;
    int curSum = 0;
    for (int i = 0; i < n; i++) {
        if (pages[i] > numPages) {
            return false;
        }
        if (curSum + pages[i] > numPages) {
            /* Increment student count by '1'*/
            cntStudents += 1;
            /* assign current book to next student and update curSum */
            curSum = pages[i];
            /* If count of students becomes greater than given no. of students, return False*/
            if (cntStudents > m) {
                return false;
            }
        } else {
            /* Else assign this book to current student and update curSum */
            curSum += pages[i];
        }
    }
    return true;
}

int allocateBooks(int pages[], int n, int m) {
    /* If number of student is more than number of books */
    if (n < m) {
        return -1;
    }
    /* Count total number of pages, so that upper limit of numPages becomes = sum */
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pages[i];
    }
    /* Check for every possible value */
    for (int numPages = 1; numPages <= sum; numPages++) {
        if (isPossible(pages, n, m, numPages)) {
            return numPages;
        }
    }
    return -1;
}

int main() {
   
    int n, m;

    cout<<"\nEnter no. of books to be allocated : ";
    cin>>n;

    cout<<"\nEnter no. of students : ";
    cin>>m;

    int pages[100];

    cout<<"\nEnter the no. of pages in the books : ";
    
    for(int i=0; i<n; i++) {
        cin>>pages[i];
    }

    cout << "\nThe minimum value of the maximum number of pages allocated in book allocation is : " << allocateBooks(pages, n, m) << endl;
}