#include <iostream>
#include <string>
using namespace std;

class Node;
class HeadNode
{
public:
	Node *next;
	string nameofcity;
	int Cityidx;

	HeadNode()
	{
		nameofcity = "0";
		Cityidx = 0;
		next = NULL;
	}
};

class Node
{
public:
	Node *next;
	string name;
	int idx;
	int dep;
	int arr;
	int sizeOfP;
	int *prices = new int[];
	int km; //for fareCalculator functionality

	Node(string n, int i, int d, int a, int s, int p[])
	{
		next = NULL;
		name = n;
		idx = i;
		dep = d;
		arr = a;
		sizeOfP = s;
		km = 0;

		for (int i = 0; i < sizeOfP; i++)
		{
			prices[i] = p[i];
		}
	}
};

class LinkedList
{
private:
	HeadNode *head;
public:
	LinkedList()
	{
		head = NULL;
	}
	void newCity(string n, int i)
	{
		HeadNode *ptr = new HeadNode;
		if (head == NULL)
		{
			ptr->nameofcity = n;
			ptr->Cityidx = i;
		}
		else cout << "Error" << endl;
		
		head = ptr;

	}
	string getName()
	{
		return head->nameofcity;
	}

	int getIDX()
	{
		return head->Cityidx;
	}

	void newLink(string n, int i, int d, int a, int p[], int size)
	{
		Node *ptr = new Node(n, i, d, a, size, p);

		if (head->next == NULL)
		{
			head->next = ptr;
		}
		else
		{
			Node *temp = head->next;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
		}
	}

	/*int checkExistence(string s)
	{
		if (head->next == NULL)
		{
			cout << "Case 1" << endl;
			return 0;
		}
		else
		{
			Node *temp = head->next;

			while (s != temp->name && temp != NULL)
			{
				cout << "Case 2" << endl;
				temp = temp->next;
			}

			if (temp == NULL)
			{
				cout << "Case 3" << endl;
				return 0;
			}
			else
			{
				cout << "Case 4" << endl;
				if (temp->name == s)
				{
					cout << "Case 4" << endl;
					return 1;
				}
				else return 0;
			}

		}
	}*/

	void searchDisplay(string n)
	{
		if (head->next != NULL)
		{
			Node *temp = head->next;

			while (temp->name != n && temp != NULL)
			{
				temp = temp->next;
			}
			if (temp != NULL)
			{
				system("cls");
				cout << "\t\t----------- Details Of Available Route ------------" << endl << endl << endl;
				cout << "\t\tFrom: " << head->nameofcity;
				cout << "\t\tTo: " << temp->name << endl << endl;

				cout << "\t\tDeparture: " << temp->dep << ":00";
				cout << "\t\tArrival: " << temp->arr << ":00" << endl << endl;

				cout << "\t\tOptions: " << endl << endl;

				for (int i = 0; i < temp->sizeOfP; i++)
				{
					cout << "\t\tPrice: " << i + 1 << temp->prices[i] << endl;
				}
				cout << endl << endl;

				_getch();
			}
		}
	}

	void nodebynodeDisplay()
	{
		Node *temp = head->next;


		while (temp != NULL)
		{
			cout << "\t\t To: " << temp->name << endl << endl;
			cout << "\t\tDeparture: " << temp->dep << ":00";
			cout << "\t\t\tArrival: " << temp->arr << ":00";

			cout << "\n\t\t-Options-" << endl;
			for (int i = 0; i < temp->sizeOfP; i++)
			{
				cout << "\t\tClass " << i + 1 << ": " << temp->prices[i] << endl;
			}

			cout << "---------------------------------------------------------------------------------------------------------" << endl << endl;
			temp = temp->next;
		}

		_getch();
	}
};
