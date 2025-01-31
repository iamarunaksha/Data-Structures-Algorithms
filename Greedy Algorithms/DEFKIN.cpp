#include<bits/stdc++.h>             // Question is present on CodeChef at https://www.codechef.com/problems/WCE0004?tab=statement
using namespace std;               // Difficult question

int main() {

    int x, y, n;

    cin>>x>>y>>n;

    int t = n;

    vector<int> rowCount;
    vector<int> colCount;

    rowCount.push_back(0);
    colCount.push_back(0);

    while(t--) {

        int a,b;

        cin>>a>>b;

        rowCount.push_back(a);
        colCount.push_back(b);
    }

    //Size of 2D grid
    rowCount.push_back(x+1);
    colCount.push_back(y+1);

    sort(rowCount.begin(), rowCount.end());
    sort(colCount.begin(), colCount.end());

    int maxLen = INT_MIN;

    for(int i=1; i<rowCount.size(); i++) {

        int a = rowCount[i-1];
        int b = rowCount[i];

        maxLen = max(maxLen, (b-a-1));
    }

    int maxWidth = INT_MIN;

    for(int i=1; i<colCount.size(); i++) {

        int a = colCount[i-1];
        int b = colCount[i];

        maxWidth = max(maxWidth, (b-a-1));
    }

    cout<<"\nAnswer is : "<<maxLen*maxWidth<<endl;

    return 0;
}