#include<bits/stdc++.h>
using namespace std;                                                        // Better solution in terms of T.C

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagnolCheck;
unordered_map<int,bool> bottomLeftDiagnolCheck;

void printSolution(vector<vector<char>> &board, int n) {
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n ;j++) {
            cout<<board[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<char>> &board, int n) {                      // O(1)

    if(rowCheck[row] == true )
        return false;
        
    if(upperLeftDiagnolCheck[n-1+col-row] == true)
        return false;
        
    if(bottomLeftDiagnolCheck[row+col] == true)
        return false;

    return true;
}


void solve(vector<vector<char>> &board, int col, int n) {
    
    //base case
    if(col >= n) {
        printSolution(board, n);
        return;
    }

    for(int row = 0; row <n; row++) {                                            // Placing Queen at 1st cell of board & then calling recusrion for the rest
        
        if(isSafe(row, col, board, n)) {
        
        board[row][col] = 'Q';

        rowCheck[row] = true;
        upperLeftDiagnolCheck[n-1+col-row] = true;
        bottomLeftDiagnolCheck[row+col] = true;
            
        //Calling Recursion for the rest of the columns
        solve(board, col+1, n);

        //Backtracking
        board[row][col] = '-';

        rowCheck[row] = false;
        upperLeftDiagnolCheck[n-1+col-row] = false;
        bottomLeftDiagnolCheck[row+col] = false;
        }
    }
}

int main() {

    int n;
    cout<<"\nEnter the value of n (size of the board) : ";
    cin>>n;

    vector<vector<char>> board(n, vector<char>(n,'-'));
    
    int col = 0;

    cout<<"\nThe required solution(s) are : "<<endl<<endl;

    solve(board, col, n);

    return 0;
}