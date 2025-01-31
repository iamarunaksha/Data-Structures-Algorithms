#include<bits/stdc++.h>
using namespace std;                                                             // Brute-Force Approach

void printSolution(vector<vector<char>> &board, int n) {
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n ;j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n) {                 // T.C --> O(3n)

    int i = row;
    int j = col;

    //Checking left row for i,j
    while(j >= 0) {
        
        if(board[i][j] == 'Q') 
            return false;
        
        j--;
    }

    //Check upper left diagonal for i,j after re-initialization of i,j
    i = row;
    j = col;

    while(i>=0 && j>=0 ) {
        
        if(board[i][j] == 'Q')
            return false;
        
        i--;
        j--;
    }


    //Check bottom left diagonal for i,j after re-initialization of i,j
    i = row;
    j = col;

    while( i < n && j >=0) {
        
        if(board[i][j] == 'Q') 
            return false;
        
        i++;
        j--;
    }

    return true;   // If no-where Queen is found, then return true that its safe to place it at row,col.
}


void solve(vector<vector<char>> &board, int col, int n) {
    
    //base case
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    for(int row = 0; row <n; row++) {                 // Placing Queen at 1st cell of board & then calling recusrion for the rest
        
        if(isSafe(row, col, board, n)) {
        
        board[row][col] = 'Q';
            
        //Calling Recursion for the rest of the columns
        solve(board, col+1, n);

        //Backtracking
        board[row][col] = '-';
        }
    }
}



int main() {

    int n;
    cout<<"\nEnter the value of n (size of the board) : ";
    cin>>n;
    
    vector<vector<char>> board(n, vector<char>(n,'-'));
    
    int col = 0;
    
    solve(board, col, n);
    
    return 0;
}