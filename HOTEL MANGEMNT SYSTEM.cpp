#include <iostream>
#include <conio.h>

// OOP Project

using namespace std;
class add
{
public:
	int n;
	string ac;
	string lcd;
	int rate;
	string status;
	add()
	{
		n = 0;
		ac = "\0";
		lcd = "\0";
		rate = 0;
		status = "free";
	}
	int rrate()
	{
		return rate;
	}
	int rn()
	{
		return n;
	}
	int get(add *tem)
	{
		int t;
		add *a = tem;
	lable:
		cout << "enter the room number: " << endl;
		cin >> t;
		for (int i = 0; i < 30; i++)
		{
			if (a->n == t)
			{
				cout << "\nAlready Added\n";
				goto lable;
			}
			++a;
		}
		n = t;
		cout << "for ac yes/no: " << endl;
		cin >> tem->ac;
		cout << "for lcd yes/no: " << endl;
		cin >> tem->lcd;
		cout << "enter the rate: " << endl;
		cin >> tem->rate;
		cout << "rommm successfully added: " << endl;
		system("cls");
	}
};
class search : public add
{
public:
	int key;
	void get1(add *tem)
	{
		cout << "enter the key: " << endl;
		cin >> key;
		int t = 0;
		for (int i = 0; i < 30; i++)
		{
			if (key == tem->n)
			{

				cout << "room number: " << tem->n << endl;
				cout << "ac::" << tem->ac << endl;
				cout << "lcd::" << tem->lcd << endl;
				cout << "rate: " << tem->rate << endl;
				cout << "Status: " << tem->status << endl;
				++t;
				break;
			}
			++tem;
		}
		if (t == 0)
			cout << "not found " << endl;
		return;
	}
};
class customer : public add
{
public:
	int id;
	char name[50];
	char address[50];
	int phone;
	int room;
	int date;
	int datee;
	int pay;
	customer()
	{
		id = 0;
		address[0] = '\0';
		name[0] = '\0';
		phone = 0;
		room = 0;
		date = 0;
		datee = 0;
		pay = 0;
	}
	int get2(add *tem, customer *cus)
	{
		cus->n = tem->n;
		cout << "\n Room No.:" << tem->n;
		cout << "\n\nenter the name: " << endl;
		cin.ignore();
		cin.getline(cus->name, 50);
		cout << "enter the id: " << endl;
		cin >> cus->id;
		cout << "enter the address: " << endl;
		cin.ignore();
		cin.getline(cus->address, 50);
		cout << "enter the phone number: " << endl;
		cin >> cus->phone;
		cout << "enter the date: " << endl;
		cin >> cus->date;
		cout << "the date to the customer want to saty: " << endl;
		cin >> cus->datee;
		cout << "advance pay: " << endl;
		cin >> cus->pay;
		cus->status = "booked";
		tem->status = "booked";
		cus->n = tem->n;
		cus->ac = tem->ac;
		cus->lcd = tem->lcd;
		cus->rate = tem->rate;
		cout << "room number: " << tem->n << endl;
		cout << "Ac:" << tem->ac << endl;
		cout << "Lcd:" << tem->lcd << endl;
		cout << "rate: " << tem->rate << endl;
		cout << "\n\n\t\tDone.......\n";
	}
	int search_id(int k, customer *tem)
	{
		int idd = k;
		int t = 0;
		for (int i = 0; i < 30; i++)
		{
			if (tem->id == idd)
			{
				cout << "\nI'D:" << tem->id;
				cout << "\nname: " << tem->name << endl;
				cout << "\naddress: " << tem->address;
				cout << "\nphone number: " << tem->phone;
				cout << "\n DATE: " << tem->date;
				cout << "\n to stay: " << tem->datee;
				cout << "\n advance pay: " << tem->pay;
				++t;
				break;
			}
			++tem;
		}
		if (t == 0)
		{
			cout << "\n\nnot found................ " << endl;
			getch();
		}
	}
};
class delet
{
	int idd;

public:
	void delete_id(int k, customer *tem, add *a)
	{
		idd = k;
		int t = 0;
		for (int i = 0; i < 30; i++)
		{
			if (tem->id == idd)
			{
				tem->id = 0;
				tem->name[0] = '\0';
				tem->address[0] = '\0';
				tem->phone = 0;
				tem->date = 0;
				tem->datee = 0;
				tem->pay = 0;
				tem->lcd = "\0";
				tem->ac = "\0";
				tem->rate = 0;

				tem->status = "free";
				++t;
				for (int j = 0; j < 30; j++)
				{
					if (tem->n == a->n)
					{
						a->status = "free";
						break;
					}
					++a;
				}
				tem->n = 0;
				break;
			}
			++tem;
		}
		if (t == 0)
			cout << "\n\nNot found................ " << endl;
		else
		{
			cout << "\n\n\t\tDeleted.................";
			getch();
		}
	}
};
int main()
{
	char ch;
	string x, y;
	int r, t, u, v;
	int choice;
	add arr[30];
	search s;
	delet d;
	customer c[30];
	while (1)
	{
	label:
		system("cls");
		cout << "********************************************************" << endl;
		cout << "\t\t\tHOTEL MENUE" << endl;
		cout << "********************************************************" << endl;
		cout << "\n1. for add room";
		cout << "\n2. for search room";
		cout << "\n3. for customer booking";
		cout << "\n4. for customer find";
		cout << "\n5. Delete customer";
		cout << "\n6. Customer Summary";
		cout << "\n\nEnter the choice according to menue: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		lable:
			r = -1;
			for (int i = 0; i <= 30; i++)
			{
				if (arr[i].rn() == 0 && arr[i].rrate() == 0)
				{
					r = i;
					break;
				}
			}
			if (r == -1)
				cout << "already enterd" << endl;
			else
			{
				arr[r].get(&arr[r]);
				cout << "do you want to add more (press y): " << endl;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					goto lable;
				}
			}
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
			break;

		case 2:
			s.get1(&arr[0]);
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
			break;
		case 3:
			cout << "\n---------------------------Room Booking------------------------------\n\n";
			cout << "AC (yes/no)::";
			cin >> x;
			cout << "\nLCD::";
			cin >> y;
			r = 31;
			for (int i = 0; i < 30; i++)
			{
				if (arr[i].ac == x && arr[i].lcd == y && arr[i].status == "free")
				{
					t = i;
					++r;
					break;
				}
			}
			if (r == 31)
			{
				cout << "\nNot Available....";
				getch();
			}

			if (r == 32)
			{
				u = -1;
				for (int i = 0; i < 30; i++)
				{
					if (c[i].id == 0 && c[i].phone == 0)
					{
						u = i;
						break;
					}
				}
				c[r].get2(&arr[t], &c[u]);
			}
			cout << "\n\n\n\t\t\tPress any key to go back..............";
			getch();
			goto label;
			break;
		case 4:
			cout << "\n\nSearch Customer---------------------------------------\n\n";
			cout << "\n\nCustomer I'D::";
			cin >> u;
			c[r].search_id(u, &c[0]);
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
		case 5:
			cout << "\n\nDelete Customer---------------------------------------\n\n";
			cout << "\n\nCustomer I'D::";
			cin >> u;
			d.delete_id(u, &c[0], &arr[0]);
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
		case 6:
			cout << "\n--------------------------------Customer Summary--------------------------------\n\n";
			for (int i = 0; i < 30; i++)
			{
				u = -1;
				if (c[i].id != 0 && c[i].n != 0)
				{
					u = c[i].id;
					c[r].search_id(u, &c[0]);
					cout << "\n\n-----------------------------------------------------------";
				}
			}
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
		default:
			cout << "invalid choice: " << endl;
			cout << "\n\n\t\tPress any key to go back..............";
			getch();
			goto label;
		}
	}
}
