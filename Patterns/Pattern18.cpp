#include<iostream>                                              
using namespace std;

int main()
{
    int rows; // Square pattern of Increment Numbers from Right Side

    cout<<"\nEnter no. of rows : ";
    cin>>rows;

    cout<<"\nThe required pattern is :\n"<<endl;

    for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= rows - i; j++)
		{
			cout << "1 ";
		}
		for (int k = 1; k <= i; k++)
		{
			cout << i << " ";
		}

       cout<<endl;
    }

    return 0;
}
