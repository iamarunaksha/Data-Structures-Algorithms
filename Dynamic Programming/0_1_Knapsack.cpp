#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)  {
	
    int index = n-1;					// Right to left movement. Index is at last element of the array

	//Base Case
	if(index == 0) {					// Only 1 element in the weight array at 0th index

		if(weight[index] <= maxWeight)
			return value[index];
		
		else
			return 0;
	}

	//Include
	int include = 0;
	
	if(weight[index] <= maxWeight)
		include = value[index] + knapsack(weight, value, index, (maxWeight - weight[index]));

	//Exclude
	int exclude = 0 + knapsack(weight, value, index, maxWeight);

	return max(include, exclude);
}

int main() {

    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};

    int n = weight.size();              // Size of the weight & value array (both needs to be same always)

    int maxWeight = 5;                 // Decided as per the problem statement

    cout<<"Ans : "<<knapsack(weight, value, n, maxWeight);

    return 0;
}