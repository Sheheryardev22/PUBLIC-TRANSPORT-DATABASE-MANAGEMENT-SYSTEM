#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


class Area
{
public:

	string name;
	int km;
	int ind;
	Area *next;

	Area(string n, int k, int i)
	{
		name = n;
		km = k;
		ind = i;
		next = NULL;
	}
};

class AreaGraph
{
private:
	Area *head;
public:

	AreaGraph()
	{
		head = NULL;
	}

	//to add a new area on the map/area
	void NewArea(string n, int i)
	{
		if (head != NULL)
		{
			cout << "ERROR 6 - AREAGRAPH(RELATING THE CREATION OF HEAD NODE)" << endl << endl;
		}
		else
		{
			Area *ptr = new Area(n, 0, i);
			head = ptr;
		}
	}

	//to form links between different areas
	void newPath(string n, int k, int i)
	{
		if (head == NULL)
		{
			cout << "ERROR 9" << endl << endl;
		}
		else
		{
			Area *ptr = new Area(n, k, i);

			Area *temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}

			temp->next = ptr;

		}
	}

	string getName()
	{
		return head->name;
	}

	void displayDetails(string des)
	{
		if (head != NULL)
		{
			Area *temp = head;

			while (temp->name != des)
			{
				temp = temp->next;
			}

			if (temp->name != des)
			{
				cout << "NO PATH BETWEEN THE ENTERED AREAS" << endl << endl;
			}

			else
			{
				cout << endl << endl;
				cout << "\t\t\tFROM: " << head->name;
				cout << "\t\t\tTO: " << temp->name;

				cout << endl << endl;

				cout << "\t\t\tDISTANCE: " << temp->km << " KM"; 
				cout << "\t\t\tESTIMATED COST: " << fareCal(temp->km) << " PKR";

				cout << endl << endl;

				_getch();
			}
		}

	}

	int fareCal(int x)
	{
		return x * 2.3;
	}
};