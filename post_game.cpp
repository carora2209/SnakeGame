#include"post_game.h"
#include<iostream>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<stdio.h>
#include<cstdio>
#include<cstring>
#include<string>


using namespace std;

// menu function to show user the menu after he/she is exited the game.
int post_game::menu()
{	
	system("cls");
	cout << "We hope your game went well :\n";
	while (1)
	{
		int input;
		cout << "Press 1 to make a private chat:\n";
		cout << "Press 2 to send messages(group) :\n";
		cout << "Press 3 to see a chat:\n";
		cout << "Press 4 to exit\n";
		cin >> input;
		if (input == 1)
		{
			return 1;
			break;
		}
		else if (input == 2)
		{
			return 2;
			break;
		}
		else if (input == 3)
		{
			return 3;
			break;
		}
		else if (input == 4)
		{
			return 4;
		}
		else
		{
			cout << "INVALID ENTRY\n";
			return -1;
		}
	}
}

// function to private chat with a user, it takes in the login id of the user and sends the message  by calling the direct message function 
void post_game::private_chat(char* cred)
{
	char code[7];
	char id[100];
	while (1)
	{	
		cout << "Enter the ID of the person you want to chat with :\n";
		cin >> id;
		if (username_check(id))
		{
			break;
		}
		else
		{
			cout << "NOT AN EXISTING USER PRESENT\n";
		}

	}
	int input;
	while (1)
	{	
		fstream f1;
		cout << "Enter 1 if this your first time messaging this person\n";
		cout << "Enter 2 if you have texted before:\n";
		cin >> input;
		if (input == 1)
		{	
			cout << "SETUP: Enter a unique code for your conversation\n";
			for (int i=0;i<6;i++)
			{
				cin >> code[i];
			}
			code[6] = '\0';
			/*cout << code;*/
			f1.open(code, ios::out);
			cout << "Successful -file created:";
			direct_message(cred);
			break;
		}
		else if (input == 2)
		{	
			direct_message(cred);
			break;
		}
		else
		{
			cout << "INVALID ENTRY";
		}
	}
		
}

// Send message - is to send and write messages in the group chat
void post_game::send_message(const char* id)
{	
	char name[100];
	string message;
	fstream f1;
	cout << "Enter the file name :\n";
	cin >> name;
	cout << "Enter your message :\n";
	cin.ignore();
	getline(cin,message);
	//open file in app mode:
	f1.open(name,ios::app);
	f1 << "\n";
	f1 << id;
	f1 << ":";
	f1 << message;
	f1.close();
}

// This handles the message sending process in private message 
void post_game::direct_message(char* cred)
{	
	system("cls");
	fstream f1;
	char code[7];
	string message;
	bool file;

	while (1)
	{
		cout << "Enter the six letter confidential code\n";
		for (int i = 0; i < 6; i++)
		{
			cin >> code[i];
		}
		code[6] = '\0';
		f1.open(code, ios::in);
		if (f1)
		{	
			f1.close();
			cout << "Correct Code, Thank you very much\n";
			cout << "Enter the message you want to send\n";
			cin.ignore();
			getline(cin,message);
			cout << "Successfull";
			f1.open(code, ios::app);
			f1 << "\n";
			f1 << cred;
			f1 << ":";
			f1 << message;
			f1.close();
			break;
		}
		else
		{
			cout << "WRONG CODE:";
		}
	}
}

// See chat is a display the whole chat of the user
void post_game::seechat()
{	
	fstream f1;
	char filename[100];
	while (true)
	{
		cout << "Enter the file name :\n";
		cin >> filename;
		f1.open(filename, ios::in);
		if (f1)
		{
			while (!f1.eof())
			{
				string temp;
				getline(f1, temp);
				cout << temp << "\n";
			}
			f1.close();
			break;
		}
		else
		{
			cout << "FIle DOES NOT EXIST:";
		}
	}
	
}