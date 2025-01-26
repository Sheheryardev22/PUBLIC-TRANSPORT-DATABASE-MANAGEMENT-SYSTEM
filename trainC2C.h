#include <iostream>
#include <string>
using namespace std;

class TrainNode
{
public:
	string station;
	int arr;
	int dep;
	int cost;
	TrainNode *next;
	TrainNode *pre;

	TrainNode()
	{
		station = "-1";
		arr = -1;
		dep = -1;
		cost = -1;
		next = NULL;
		pre = NULL;
	}
	TrainNode(string n, int a, int d, int c)
	{
		station = n;
		arr = a;
		dep = d;
		cost = c;
		next = NULL;
		pre = NULL;
	}
};

class TrainCC //city to city train linkedList
{
private:
	TrainNode *start;
	TrainNode *end;
public:
	TrainCC()
	{
		start = NULL;
		end = NULL;
	}

	//customer features

	void c2c(string from, string to)
	{
		int price = 0; //calculated price

		if (start == NULL)
		{
			cout << "------------ System Down ------------" << endl << endl;
		}
		else
		{
			if (from == start->station)
			{
				//searching the destination station

				TrainNode *temp = start->next;

				while (temp->station != to && temp != start)
				{
						price += temp->cost;
						temp = temp->next;
				}

				if (temp == start)
				{
					cout << "NO AVALABLE TRAIN ON THE REQUIRED ROUTE" << endl << endl;
				}
				else
				{
					price += temp->cost;

					displayInfo(start, temp, price);
				}
			}
			else
			{

				TrainNode *c1 = start->next;

				//finding starting station 
				while (c1->station != from && c1 != start)
				{
					c1 = c1->next;
				}

				TrainNode *c2 = c1->next;

				while (c2->station != to && c2 != c1)
				{
					price += c2->cost;
					c2 = c2->next;
				}
				price += c2->cost;

				displayInfo(c1, c2, price);

			}
		}
	}


	void displayInfo(TrainNode *s1, TrainNode *s2, int c)
	{
		cout << "\n\n\n\n\t\t\t------------INFORMATION------------" << endl << endl;

		cout << "\t\t\tFrom: " << s1->station;
		cout << "\t\tTo: " << s2->station;

		cout << endl << endl;


		cout << "\t\t\tDEPARTURE: " << s1->dep << ":00";
		cout << "\t\tARRIVAL: " << s2->arr << ":00";

		cout << endl << endl;

		cout << "\t\t\t\tCOST: " << c;

		cout << endl << endl;
		_getch();
	}



	//Admin Features 
	//----------------------------------
	void AddNewStation(string n, int a, int d, int c, int ch)
	{
		TrainNode *ptr = new TrainNode(n, a, d, c);
		
		if (ch == 1) //starting station
		{
			insert_first(ptr);
		}
		else if (ch == 2) //last station
		{
			insert_last(ptr);
		}
		else if (ch == 3)//station will be added in a specific location
		{
			cout << "Position: ";
			int x;
			cout << ">> ";
			cin >> x;

			insert_specific(ptr, x);
		}
	}

	void insert_first(TrainNode *ptr)
	{

		if (start == NULL) //case 0 elements
		{
			ptr->next = ptr;
			ptr->pre = ptr;
			start = ptr;
			end = ptr;
		}
		else
		{
			ptr->next = start;
			ptr->pre = end;
			start->pre = ptr;
			start = ptr;
		}
	}

	void insert_last(TrainNode *ptr)
	{
			if (start == NULL) //case: 0 elements in the list
			{
				ptr->next = ptr;
				ptr->pre = ptr;
				start = ptr;
				end = ptr;
			}
			else
			{
				ptr->next = start;
				ptr->pre = end;

				end->next = ptr;
				end = ptr;
			}
	}

	void insert_specific(TrainNode *ptr, int pos)
	{
		
		if (start == NULL) //case: 0 elements
		{
			if (pos != 1)
			{
				cout << "NO PREVIOUS STATIONS ADDED - POSITION INVALID -  ONLY VALID INPUT = 1" << endl << endl;
			}
			else
			{
				ptr->next = ptr;
				ptr->pre = ptr;
				start = ptr;
				end = ptr;
			}
		}
		else if (start->next == NULL) //case: 1 element
		{
			if (pos == 1)
			{
				ptr->next = start;
				start->pre = ptr;
				ptr->pre = end;
				start = ptr;
			}
			else if (pos == 2)
			{
				ptr->next = start;
				ptr->pre = start;
				start->next = ptr;
				end = ptr;
			}
			else cout << "Wrong Position" << endl << endl;
		}
		else
		{
			int counter = 1;

			if (pos == 1)
			{
				ptr->next = start;
				ptr->pre = end;
				start->pre = ptr;
				start = ptr;
			}
			else
			{
				TrainNode *temp = start;

				while (counter != pos - 1) //to find the previous element to the position
				{
					temp = temp->next;
					counter++;
				}
				if (temp == end) //if the desired position is the end of the list
				{
					ptr->pre = end;
					ptr->next = start;
					end->next = ptr;
					end = ptr;
				}
				else
				{
					ptr->pre = temp;
					ptr->next = temp->next;
					temp->next->pre = ptr;
					temp->next = ptr;
				}
			}
		}
	}

	void display()
	{
		cout << "\n\n\n\n\n\n";

		TrainNode *temp = start->next;

		cout << "\t\t" << start->station << " --> ";
		while (temp->next != start)
		{
			cout << temp->station << " --> ";
			temp = temp->next;
		}
		cout << temp->station << endl << endl;
	}
};