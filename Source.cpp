#include <iostream>
#include <string>
#include <conio.h>
#include "menu.h"
#include "FareCalculator.h"
using namespace std;


int main()
{
	CityToCity Ctravel;
	Fare fareC;

	int ch;


	do
	{
		cout << "\t\t\t --- PUBLIC TRANSPORT DATABASE & MANAGEMENT SYSTEM --- " << endl << endl << endl;


		cout << "\t\t\t1- INTER-CITY TRAVELS" << endl;
		cout << "\t\t\t2- WITHIN CITY CAB FARE ESTIMATE" << endl << endl;

		cout << "\t\t\t>> ";

		cin >> ch;

		if (ch == 1)
		{
			Ctravel.data();
			Ctravel.menu();
		}
		else if (ch == 2)
		{
			fareC.data();
			fareC.fareMenu();
		}

	} while (ch != 0);



	system("pause");

}
