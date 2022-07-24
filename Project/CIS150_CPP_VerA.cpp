#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct bookinf{
	string title, category;
	int prodyear, numofcopies, edition;
}book[5];
struct userinf{
	string username, password, email, accounttype;
	int id, contact;
}user;
struct librianinf{
	string name, password;
}libarian[5];
void choice();
void signup();
void login1();
void login2();
void search();
void buy();
void datalog();
int main()
{
	libarian[0].name = { "marco" };
	libarian[0].password = { "asensio" };
	libarian[1].name = { "cristiano" };
	libarian[1].password = { "ronaldo" };
	libarian[2].name = { "sergio" };
	libarian[2].password = { "ramos" };
	libarian[3].name = { "toni" };
	libarian[3].password = { "kross" };
	book[0].title = { "guliver" };
	book[0].category = { "novel" };
	book[0].edition = 4;
	book[0].numofcopies = 20;
	book[0].prodyear = 2000;
	book[1].title = { "biology" };
	book[1].category = { "science" };
	book[1].edition = 2;
	book[1].numofcopies = 40;
	book[1].prodyear = 2010;
	book[2].title = { "realmadrid" };
	book[2].category = { "sports" };
	book[2].edition = 13;
	book[2].numofcopies = 50;
	book[2].prodyear = 2014;
	book[3].title = { "odyssy" };
	book[3].category = { "poem" };
	book[3].numofcopies = 65;
	book[3].edition = 5;
	book[3].prodyear = 1997;
	book[4].title = { "ancient" };
	book[4].category = { "history" };
	book[4].edition = 9;
	book[4].numofcopies = 88;
	book[4].prodyear = 2015;
	int response;
	cout << "\t\t\t\t\tenter your response" << endl;
	cout << "1.login" << endl;
	cout << "2.datalog" << endl;
	cin >> response;
	switch (response)
	{
	case 1:
		choice();
		break;
	case 2:
		datalog();
		break;
	default:
		cout << "incorrect choice" << endl;
	}
}
void choice()
{
	int respone1;
	string acc, pass;
	cout << "1.user" << endl;
	cout << "2.libarian" << endl;
	cin >> respone1;
	switch (respone1)
	{
	case 1:
		login1();
		break;
	case 2:
		login2();
		break;
	default:
		cout << "incorrect choice" << endl;
		break;
	}
}
void login2()
{
	string username, password;
	int y;
	cout << "enter your name" << endl;
	cin >> username;
	cout << "enter your password" << endl;
	cin >> password;
	for (int i = 0; i < 4; i++)
	{
		if ((username == libarian[i].name) && (password == libarian[i].password))
		{
			y = 1;
		}
	}
	if (y == 1)
	{
		cout << "correct login" << endl;
		signup();
	}
	else
	{
		cout << "invalid login" << endl;
		main();
	}



}
void signup()
{
	string username, password;
	ofstream infile;
	infile.open("data.txt", ios::app);
	cout << "Enter your name" << endl;
	cin >> user.username;
	cout << "Enter your email" << endl;
	cin >> user.email;
	cout << "Enter your password" << endl;
	cin >> user.password;
	cout << "Enter your accounttype" << endl;
	cin >> user.accounttype;
	cout << "Enter your id" << endl;
	cin >> user.id;
	infile << user.username << "\t" << user.email << "\t" << user.password << "\t" << user.accounttype << endl;
	cout << "Enter your  contact number" << endl;
	cin.ignore();

	cin >> user.contact;
	cout << "signup done" << endl;
	main();


}
void login1()
{
	int action, i = 0;
	string acc, pass, user, password, name, acc_type;
	cout << "Enter username" << endl;
	cin >> acc;
	cout << "Enter Password" << endl;
	cin >> pass;
	fstream infile;
	infile.open("data.txt");
	while (infile >> name >> user >> password >> acc_type)
	{
		if (acc == user && pass == password);
		i = 1;
	}
	if (i == 1)
	{
		cout << "correct login" << endl;
		if (acc_type == "staff")
		{
			cout << "1.search" << endl;
			cout << "2.buy" << endl;
			cin >> action;
			switch (action)
			{
			case 1: search();
				break;
			case 2:buy();
				break;
			default:
				cout << "incorrect choice" << endl;
				break;
			}
		}
		else
		{
			search();
		}
	}
	else
	{
		cout << "invalid login" << endl;
	}
}
void search()
{

	string title;
	int z = 0;
	cout << "enter book title" << endl;
	cin >> title;
	fstream infile;
	infile.open("book.txt");
	for (int x = 0; x < 5; x++)
	{
		if (title == book[x].title)
			z = 1;
	}
	if (z == 1)

	{
		cout << "book exist" << endl;

	}
	else
		cout << "book doesnot exist" << endl;
}
void buy()
{
	string book1;
	cout << "what would you like to buy" << endl;
	cin >> book1;
	for (int j = 0; j < 5; j++)
	{
		if (book1 == book[j].title)
		{
			book[j].numofcopies -= 1;
			cout << book[j].numofcopies << endl;
			cout << "process is completed" << endl;
		}
		else
		{
			buy();
		}
	}
}
void datalog()
{
	string username, email, password, accounttype;
	int y;
	cout << "\t\t\t\t**" << endl;
	cout << "enter your name" << endl;
	cin >> username;
	cout << "enter your password" << endl;
	cin >> password;
	for (int i = 0; i < 4; i++)
	{
		if ((username == libarian[i].name) && (password == libarian[i].password))
		{
			y = 1;
		}
	}
	if (y == 1)
	{
		cout << "correct login" << endl;
	}
	else
	{
		cout << "invalid login" << endl;
		main();
	}
	ifstream file;
	file.open("data.txt");
	while (file >> username >> email >> password >> accounttype)
	{
		cout << username << "\t" << password << "\t" << accounttype << "\t" << email << endl;
	}
	main();
}
