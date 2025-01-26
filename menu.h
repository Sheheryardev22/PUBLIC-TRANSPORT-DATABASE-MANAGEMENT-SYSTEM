#include <iostream>
#include "citiesGraph.h"
#include "trainC2C.h"
#include <conio.h>

class CityToCity
{
public:

	int citiesNo;
	LinkedList cities[20];
	TrainCC trains;

	CityToCity()
	{
		citiesNo = 0;
	}
	void admin();
	void menu();
	void data();
	void search(string, string);
	void allRoutes();
	void busMenu();
	void trainMenu();
};




void CityToCity::menu()
{
	system("cls");

	int choice;
	
	
	do
	{

		cout << "\t\t\t\t----- INTERCITY TRAVEL -----" << endl << endl;

		cout << "\t\t\t1.TRAVEL BY BUS";
		cout << "\t\t\t2. TRAVEL BY TRAIN";

		cout << endl << endl;

		cout << "\t\t\t>> ";
		choice = _getch();

		if (choice == '1')
		{
			busMenu();
		}
		else if (choice == '2')
		{
			trainMenu();
		}
	} while (choice != 8);
}


void CityToCity::trainMenu()
{
	system("cls");
	int choice;
	string s1, s2;

	cout << "\t\t\tTRAIN TRAVEL" << endl << endl;

	do
	{
		system("cls");
		cout << "\t\t\t1- SEARCH";
		cout << "\t\t\t2- VIEW COMPLETE ROUTE";
		
		cout << endl;

		cout << "\t\t\t>> ";
		choice = _getch();

		if (choice == '1')
		{
			system("cls");
			cout << "\t\t\tFROM: ";
			cin.ignore();
			getline(cin, s1);
			cout << "\t\t\tTO: ";
			getline(cin, s2);
			system("cls");
			trains.c2c(s1, s2);
		}
		else if (choice == '2')
		{
			system("cls");

			cout << "\t\t\t-----------------    COMPLETE ROUTE    -----------------" << endl << endl;
			cout << "\t\t\t-----------------INTER CITY TRAIN ROUTE-----------------" << endl << endl;


			trains.display();

			_getch();

			system("cls");
		}

	} while (choice != 8);
}

void CityToCity::busMenu()
{
	system("cls");

	string s1, s2;


	int ch;

	do
	{
		system("cls");
	    
		cout << "\t\t\t\tINTERCITY BUS ROUTES" << endl << endl;
		cout << "\t\t\t1- SEARCH";
		cout << "\t\t\t2- VIEW ALL RUOTES" << endl;
		ch = _getch();

		if (ch == '1')
		{
			system("cls");
			cout << "\t\t\tFROM: ";
			cin.ignore();
			getline(cin, s1);
			cout << "\t\t\tTO: ";
			getline(cin, s2);
			
			
			search(s1, s2);
		}
		else if (ch == '2')
		{
			system("cls");
			allRoutes();
		}
	} while (ch != 8);
	
	menu();

}


	void CityToCity::admin()
	{
		int choice;

		cout << "---Admin Panel---" << endl << endl;

		cout << "1. Add A New City To The List" << endl << endl;
		cout << "2. Add A New Link Between Two Cities" << endl;

		cout << ">> ";
		cin >> choice;

		if (choice == 1)
		{
			string s;
			cout << "City's Name: ";
			cin >> s;

			cities[citiesNo].newCity(s, citiesNo);
			citiesNo++;
		}
		else if (choice == 2)
		{
			string c1, c2;

			cout << "From: ";
			cin.ignore();
			getline(cin, c1);
			cout << "To: ";
			getline(cin, c2);


			int idx1 = 0;
			int idx2 = 0;
			for (int i = 0; i < citiesNo; i++)
			{
				string temp = cities[i].getName();
				if (temp.compare(c1) == 0)
				{
					idx1 = i;
					break;
				}
			}

			cout << "Check: " << cities[idx1].getName() << endl;
			cout << "IDX: " << idx1 << endl;

			for (int i = 0; i < citiesNo; i++)
			{
				string temp = cities[i].getName();
				if (temp.compare(c2) == 0)
				{
					idx2 = i;
					cout << "Found 1 - No Issues" << endl << endl;
					break;
				}
				else cout << "Loop Issues" << endl << endl;
			}

			cout << "Check 2: " << cities[idx2].getName() << endl;
			cout << "IDX 2: " << idx2 << endl;

			if (true) //no previous link
			{
				cout << "Existence" << endl;
				int d, a, s, p;
				int *price = new int[];

				cout << "--- Details --- " << endl << endl;
				cout << "Departure Time: ";
				cin >> d;
				cout << "Arrival Time: ";
				cin >> a;
				cout << "Number Of Price Packages: ";
				cin >> s;

				for (int i = 0; i < s; i++)
				{
					cout << "Package " << i + 1 << ": ";
					cin >> p;
					price[i] = p;
				}

				cities[idx1].newLink(c2, idx2, d, a, price, s);
				cout << "Linked" << endl;
			}
			else cout << "Error" << endl << endl;
		}

	}

	void CityToCity::search(string c1, string c2) //bus search fucntion
	{

		int idx1 = 0;
		int idx2 = 0;
		bool check = false;

		for (int i = 0; i < citiesNo; i++)
		{
			if (c1.compare(cities[i].getName()) == 0)
			{
				idx1 = i;
				check = true;
				break;
			}
		}


		if (check == true)
		{
			if (/*cities[idx1].checkExistence(c2) == 1*/ true)
			{
				cities[idx1].searchDisplay(c2);
			}
			else cout << "Issue In Search and Display Function" << endl << endl;
		}
		else cout << "Not True" << endl;

	}

	void CityToCity::allRoutes() //bus display function
	{
		system("cls");

		string start;
		cout << "Your City: ";
		cin >> start;

		int idx = 0;
		for (int i = 0; i < citiesNo; i++)
		{
			string cn;
			cn = cities[i].getName();
			if (cn == start)
			{
				idx = i;
			}
		}

		cout << "\t\t\t\t\t--- From " << start << " ---" << endl << endl;
		cities[idx].nodebynodeDisplay();
		cout << endl << endl;
	}

void CityToCity::data()
{
	cities[0].newCity("Lahore", 0);
	cities[1].newCity("Multan", 1);
	cities[2].newCity("Faisalabad", 2);
	cities[3].newCity("Islamabad", 3);
	cities[4].newCity("Karachi", 4);
	cities[5].newCity("Quetta", 5);
	cities[6].newCity("Peshawar", 6);

	citiesNo = 7;

	int size = 2;
	int *p = new int[size];

	size = 2;
	p[0] = 2300;
	p[1] = 5400;

	cities[0].newLink("Multan", 1, 7, 12, p, size);

	size = 3;
	p[0] = 6500;
	p[1] = 8740;
	p[2] = 11300;

	cities[0].newLink("Karachi", 4, 2, 23, p, 3);


	size = 2;
	p[0] = 3500;
	p[1] = 5740;

	cities[0].newLink("Islamabad", 3, 1, 6, p, 2);

	size = 2;
	p[0] = 11500;
	p[1] = 25740;

	cities[4].newLink("Quetta", 2, 23, 5, p, 2);


	size = 2;
	p[0] = 13500;
	p[1] = 15340;

	cities[4].newLink("Peshawar", 6, 3, 21, p, 2);

	size = 3;
	p[0] = 7650;
	p[1] = 16000;
	p[2] = 23500;

	cities[4].newLink("Faisalabad", 2, 9, 6, p, 3);


	//----------------------------
	//Train Data

	trains.AddNewStation("Lahore", 1, 2, 11200, 2);
	trains.AddNewStation("Multan", 5, 9, 2200, 2);
	trains.AddNewStation("Faisalabad", 11, 5, 2500, 2);
	trains.AddNewStation("Rawalpindi", 21, 2, 5200, 2);
	trains.AddNewStation("Islamabad", 11, 24, 1200, 2);
	trains.AddNewStation("Hyderabad", 11, 6, 5500, 2);
	trains.AddNewStation("Karachi", 19, 7, 11200, 2);
}