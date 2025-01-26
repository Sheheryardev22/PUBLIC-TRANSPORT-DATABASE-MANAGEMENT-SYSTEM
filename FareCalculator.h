#include <iostream>
#include "areaGraph.h"
#include <string>
using namespace std;

class Fare
{
private:
	AreaGraph Areas[20];
	int areaNo;
	int price;
public:
	Fare();
	void calculator(string a1, string a2);
	void data();
	void fareMenu();
	void displayAreas();
};

Fare::Fare()
{
	price = 0;
}

void Fare::fareMenu()
{
	system("cls");
	
	displayAreas();

	string s1, s2;
	int ch;

	do
	{
		cout << "\t\t\tCAB FARE CALULATOR" << endl << endl;

		cout << "\t\t\tFROM: ";
		cin.ignore();
		getline(cin, s1);
		cout << "\t\t\tTO: ";
		getline(cin, s2);

		calculator(s1, s2);

		ch = _getch();
	} 
	while (ch != 8);
	
}

void Fare::displayAreas()
{
	cout << "\t\t\tAREAS WITHIN THE SYSTEM" << endl << endl;

	for (int i = 0; i < areaNo; i++)
	{
		cout << "- " << Areas[i].getName() << endl;
	}

	cout << endl << endl;
}

void Fare::calculator(string a1, string a2)
{
	int idx;

	for (int i = 0; i < areaNo; i++)
	{
		if (Areas[i].getName() == a1)
		{
			idx = i; //the index of the starting point
			break;
		}
	}

	Areas[idx].displayDetails(a2);



}

void Fare::data()
{
	Areas[0].NewArea("DHA", 0);
	Areas[1].NewArea("Gulberg", 1);
	Areas[2].NewArea("Fortress", 2);
	Areas[3].NewArea("Johar Town",3);
	Areas[4].NewArea("West Wood",4);
	Areas[5].NewArea("Motor Way",5);

	areaNo = 6;

	Areas[0].newPath("Gulberg", 10, 1);
	Areas[0].newPath("Fortress", 15, 2);
	Areas[0].newPath("Gulberg", 10, 1);

	Areas[1].newPath("DHA", 10, 1);



}