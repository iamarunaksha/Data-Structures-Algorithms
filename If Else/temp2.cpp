#include <iostream>                    //taking value and unit at the same time
#include <cctype>
using namespace std;

int main()
{
	float temp, cels, fahr;
	char unit;

	cout << "\nPlease enter the temperature and measurement system (C or F): ";
	cin >> temp >> unit;
	
	if ( isupper(unit) )            //if uppercase C or F is present then this if statement occurs
	{
		unit = tolower(unit);      //converts uppercase to lowercase
	}

	if (unit == 'f')
	{
		cels = (temp - 32) * 5/9;
		cout <<"\n"<< temp <<" degree fahrenheit is = "<< cels << " degrees Celsius\n";
	}
	else if (unit == 'c')
	{
		fahr = (9.0 / 5.0) * temp + 32;
		cout <<"\n"<< temp <<" degree celsius is = " << fahr<<" degrees Fahrenheit\n";
	}
	else
	{
		cout << "Sorry the unit of measurement isn't recognized around here.\n";
	}

    cout<<endl;

	return 0;
}