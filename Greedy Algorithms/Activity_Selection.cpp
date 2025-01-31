#include<bits/stdc++.h>             // Code for general Activity Selection Problem || N meetings in a room
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

//N trains on a platform
int solve(int n, int arr[], int dept[]) {           // T.C --> O(nlogn)  || S.C --> O(n)

    vector<pair<int, int>> data;

    for(int i=0; i<n; i++) {

        pair<int, int> temp = {arr[i], dept[i]};
        data.push_back(temp);
    }

    sort(data.begin(), data.end(), comparator);             // T.C --> O(nlogn)

    int count = 1;

    cout<<"\nTrain's arrival & dept time are : \n"<<data[0].first<<", "<<data[0].second<<endl;

    int lastDeptTime = data[0].second;

    for(int i=1; i<n; i++) {

        //Current train's arrival time >= previously "included" train's dept. time --> current train can be included
        if(data[i].first >= lastDeptTime){
            
            count++;

            lastDeptTime = data[i].second;

            cout<<data[i].first<<", "<<data[i].second<<endl;
        }
    }

    return count;
}

int main() {

    int arrival[] = {5, 8, 2, 4};
    int dept[] = {7, 11, 6, 5};

    int ans = solve(4, arrival, dept);

    cout<<"\nAns is : "<<ans<<endl;

    return 0;
}