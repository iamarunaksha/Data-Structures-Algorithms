#include<bits/stdc++.h>
using namespace std;

//Visited with -ive Marking Method
vector<int> missingElementFromArrayWithDuplicates(int *arr, int n) {    //T.C --> O(n)  || S.C --> O(1)

    vector<int> ans;

    for(int i=0; i<n; i++) {

        int index = abs(arr[i]);

        //Mark as visited
        if(arr[index - 1] > 0)
            arr[index - 1] *= -1;
    }
    
    //Indexes where there are positive elements those "(indices + 1)" (elements) are missing
    for(int i=0; i<n; i++){ 
        
        if(arr[i] > 0)
            ans.push_back(i+1);
    }

    return ans;
}

vector<int> findMissing(int arr[], int n) {         //T.C --> O(n)  || S.C --> O(1)

    vector<int> ans;
    
    int i = 0;

    while(i < n) {

        int index = arr[i] - 1;

        if(arr[i] != arr[index]) 
            swap(arr[i], arr[index]);
        
        else
            i++;
    }

    for(int i=0; i<n; i++) {

        if(arr[i] != (i+1))
            ans.push_back(i+1);
    }

    return ans;
}

void print(vector<int> &v) {

    cout<<"\nMissing elements from the array is/are : ";

    bool first = true;

    for(auto it : v) {

        if(!first)
            cout<<", ";
        
        cout<<it;

        first = false;
    }
}

int main() {

    int arr[] = {1, 3, 3, 3, 5};

    int n = sizeof(arr)/sizeof(int);

    //vector<int> res = missingElementFromArrayWithDuplicates(arr, n);

    vector<int> res = findMissing(arr, n);

    print(res);

    return 0;
}