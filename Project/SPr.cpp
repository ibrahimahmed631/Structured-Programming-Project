#include <iostream>
#include <fstream>
#include<string>
using namespace std;
struct today_date { int day; int month; int year; };
struct date { int day; int month; int year; };
struct due_date { int day; int month; int year; };
fstream task;

struct ADD { int number; string title; string description; int periority; bool mark = false; };
ADD arr[10];
void errorint(int var, int min, int max)
{
	cin >> var;
	if (var < min || var > max)
	{
		cout << "Unvalid Entry!! \n Try again:";
		cin >> var;
	}
}
void error_string(string var, int min, int max)
{
	cin >> var;
	if (var.length() < min || var.length() > max)
	{
		cout << "Unvalid Entry!! /n Try again:";
		cin >> var;
	}

}
bool errorbool(char var)
{
	char bool1 = 't'; char bool2 = 'T'; char bool3 = 'F'; char bool4 = 'f';

	while (var != bool1 && var != bool2 && var != bool3 && var != bool4)
	{
		cout << "Unvalid Entry (Please Enter T/F)!! \nTry again: ";
		cin >> var;

	}
	return true;
}
date errordate()
{
	date due_date;
	cout << " enter the date please ? \n";
	cout << "Enter Day :";
	cin >> due_date.day;
	cout << "Enter Month :";
	cin >> due_date.month;
	cout << "Enter year :";
	cin >> due_date.year;
	while (1)
	{
		if (due_date.day < 1 || due_date.day>31)
		{
			cout << "enter a valid day \n";
			cin >> due_date.day;
			continue;
		}
		if (due_date.month < 1 || due_date.month>12)
		{
			cout << "enter a valid month \n";
			cin >> due_date.month;
			continue;
		}
		if (due_date.year < 1 || due_date.year>12)
		{
			cout << "enter a valid month \n";
			cin >> due_date.year;
			continue;
		}
		else {
			break;
		}
	}
	return due_date;
}
void Edit()
{
	string task_name, title, description, periority;
	date due_date;
	bool mark;
	ofstream ta;
	//try to open file 
	task.open("task.txt", ios::in);
	ta.open("ta.txt", ios::out);
	char n[100];
	cin.ignore();
	//get title from consele
	cout << "Enter title" << endl;
	cin >> n;
	int x;
	while (task >> title >> description >> due_date.day >> due_date.month >> due_date.year >> periority >> mark)
	{
		if (n == title)
		{
			cout << " Press 1 to edit title, Press 2 to edit description, Press 3 to edit due date, press 4 to edit priority";
			cin >> x;
			switch (x) {
			case 1:
				cout << "Enter the new title";
				cin.ignore();
				getline(cin, title);
				break;
			case 2:
				cout << "Enter the new description";
				cin.ignore();
				getline(cin, description);
				break;
			case 3:
				cout << "Enter the new due date \n";
				due_date = errordate();
				break;
			case 4:
				cout << "Enter the new priority";
				cin.ignore();
				getline(cin, periority);
				break;
			default:
				cout << "invalid number";
			}
			ta << title << "\t" << description << "\t" << due_date.day << "\t" << due_date.month << "\t" << due_date.year << "\t" << periority << "\t" << mark << "\n\n";
		}
		else {
			ta << title << "\t" << description << "\t" << due_date.day << "\t" << due_date.month << "\t" << due_date.year << "\t" << periority << "\t" << mark << "\n\n";
		}
	}
	ta.close();
	task.close();
	remove("task.txt");
	rename("ta.txt", "task.txt");
}
void Delete()
{
	string task_name, title, description, due_date, periority;
	bool mark;
	//Creates an file
	// creates another  file
	ofstream ta;
	//try to open file 
	task.open("task.txt", ios::in);
	ta.open("ta.txt", ios::out);
	// get title of the task to delete it
	char n[100];
	cin.ignore();
	//get title from consele
	cout << "Enter title" << endl;
	cin >> n;
	// get data from first file
	while (task >> title >> description >> due_date >> periority >> mark)
	{
		if (n == title)
		{
			continue;
			// compare title  from user with title found in file
			//if the two titles equal each others then we will not be include in file  ; else it will put in file
		}
		else {
			ta << title << "\t" << description << "\t" << due_date << "\t" << periority << "\t" << mark << "\n\n";
		}
	}
	ta.close();
	task.close();
	remove("task.txt");
	rename("ta.txt", "task.txt");
}
void adding_task()
{
	int num;
	cout << "Enter the number of tasks you want to enter :  ";
	cin >> num;
	fstream task;
	task.open("task.txt", ios::app);
	cin.ignore();
	for (int i = 1; i <= num; i++)
	{
		cout << "Title : ";
		getline(cin, arr[i].title);
		cout << "description : ";
		getline(cin, arr[i].description);
		
		arr[i].due_date=errordate();
		cout << "Periority : ";
		cin >> arr[i].periority;
		task << arr[i].title << "\t" << arr[i].description << "\t" << arr[i].due_date.day << "\t" << arr[i].due_date.month << "\t" << arr[i].due_date.year << "\t" << arr[i].periority <<"\t"<<arr[i].mark <<"\n\n";
	}
	task.close();
	cout << "Done";
}
void mark_done()
{
	string task_name, title, description, due_date, periority;
	bool mark;
	cout << "enter task name:" << endl;
	cin >> task_name;
	task.open("task.txt");
	ofstream ta;
	ta.open("ta.txt", ios::out);
	while (task >> title >> description >> due_date >> periority >> mark)
	{
		if (task_name == title)
		{
			mark = true;
			ta << title << "\t" << description << "\t" << due_date << "\t" << periority << "\t " << mark << "\n\n";
		}
		else
		{
			ta << title << "\t" << description << "\t" << due_date << "\t" << periority << "\t " << mark << "\n\n";
		}
	}
	ta.close();
	task.close();
	remove("task.txt");
	rename("ta.txt", "task.txt");

	
}
void search() {
	string Search, title, description, due_date, periority;
	bool mark;
	cout << "Search: \n" << endl;
	cin >> Search;
	task.open("task.txt");
	while (task >> title >> description >> due_date >> periority >> mark)
	{
		if (Search == title || Search == description || Search == due_date) {
			cout << "title: " << title<< "\n";
			cout << "description: " << description << "\n";
			cout << "Due Date: " << due_date << "\n";
			cout << "Priority " << periority << "\n";
		}
	}
}
void display() {
	string Search, title, description, due_date, periority;
	bool mark;
	int disp;
	cout << "press 1 to dislay all, press 2 to display done, press 3 to display not done, press 4 to display overdue, press 5 to display tasks that must be done today";
	cin >> disp;
	switch (disp) {
	case 1:
		task.open("task.txt");
		while (task >> title >> description >> due_date >> periority >> mark) {
			cout << "title: " << title << "\n";
			cout << "description: " << description << "\n";
			cout << "Due Date: " << due_date << "\n";
			cout << "Priority " << periority << "\n";
		}
		task.close();
		break;
	case 2:
		task.open("task.txt");
		while (task >> title >> description >> due_date >> periority >> mark)
		{
			if (mark == 1) {
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";
			}
		}
		task.close();
		break;
	case 3:
		task.open("task.txt");
		while (task >> title >> description >> due_date >> periority >> mark)
		{
			if (mark == 0) {
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";
			}
		}
		task.close();
		break;
	/*case 4:
		task.open("task.txt");
		while (task >> title >> description >> due_date >> periority >> mark >> today_date)
		{

			cout << "please enter today's date to know if there are overdue tasks !" << endl;
			cin >> today_date->day;
			cin >> today_date->month;
			cin >> today_date->year;
			if (today_date->year > due_date->year)
			{
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";
			}
			else if (today_date->year == due_date.year && today_date->month > due_date->month)
			{
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";

			}
			else if (today_date->year == due_date->year && today_date->month == due_date->month && today_date->day > due_date->day)
			{
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";

			}
			else
				cout << "There are no overdue tasks!" << endl;
		}
	case 5:
		task.open("task.txt");
		while (task >> title >> description >> due_date >> periority >> mark)
		{
			cout << "please enter today's date to know if there are tasks that must be done today!" << endl;
			cin >> today_date->day;
			cin >> today_date->month;
			cin >> today_date->year;
			if (ADD-> ->year == due_date->year && today_date->month == due_date->month && today_date->day == due_date->day)
			{
				cout << "title: " << title << "\n";
				cout << "description: " << description << "\n";
				cout << "Due Date: " << due_date << "\n";
				cout << "Priority " << periority << "\n";
			}

		}*/
	
		task.close();
		break;
	default:
		cout << "invalid number";
	}
}

int main()
{
	bool flag = true;
	int num;
	while (flag)
	{
		cout << "please choose a number to customize your task!" << endl;
		cout << " press 1 : add a new task \n press 2 : mark your task as done \n press 3 : display your tasks \n press 4 : delete a task\n press 5 : edit your tasks\n press 6 : to search for a specific task " << endl;
		cin >> num;
		switch (num) {
		case 1:
			adding_task();
			break;
		case 2:
			mark_done();
			break;
		case 3:
			display();
			break;
		case 4:
			Delete();
			break;
		case 5:
			Edit();
			break;
		case 6:
			search();
			break;
		default:
			cout << "Invalid number!" << endl;
		}
		cout << "press a if you want to choose again!" << endl;
		char x;
		cin >> x;
		if (x != 'a')
			flag = false;
	}
}
