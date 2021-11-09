#include<iostream>
#include<conio.h>
#include"login.h"
#include<fstream>
#include<stdlib.h>
using namespace std;

// Function to display the big snake to the user when the project is run 
Welcome::Welcome(bool input=true)
{
    system("cls");
    cout << "\n            /^\\/^\\                                             ";
    cout << "\n          _|__|  O|                                              ";
    cout << "\n \\/     /~     \\_/ \\                                          ";
    cout << "\n  \\____|__________/  \\                                         ";
    cout << "\n         \\_______      \\                                       ";
    cout << "\n                 `\\     \\                 \\                   ";
    cout << "\n                   |     |                  \\                   ";
    cout << "\n                  /      /                    \\                 ";
    cout << "\n                 /     /                       \\\\              ";
    cout << "\n               /      /                         \\ \\            ";
    cout << "\n              /     /                            \\  \\          ";
    cout << "\n            /     /             _----_            \\   \\        ";
    cout << "\n           /     /           _-~      ~-_         |   |          ";
    cout << "\n          (      (        _-~    _--_    ~-_     _/   |          ";
    cout << "\n           \\      ~-____-~    _-~    ~-_    ~-_-~    /          ";
    cout << "\n             ~-_           _-~          ~-_       _-~   -        -";
    cout << "\n                ~--______-~                ~-___-~               \n\n\n";
    cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t_________________________WELCOME OF THE SNAKE GAME_____________________\n";
    cout << "\t\t\t\t\t\t\t\t\tDEVELOPED BY CHAITANYA ARORA----->NEPTUN CODE- BWTFX8";



}               

// Intro function is to display the first screen to the user i.e. if he is a new user or an existing user
int login::intro()
{
    int ans;
    cout << "\t\t\t\t\nWelcome!!\n\n";
    cout << "Press 1 if you are a new user\n";
    cout << "Press 2 if you are an existing user\n";
    cout << "Press 3 to exit\n";
    while (1)
    {
        cin >> ans;
        if (ans == 1)
        {
            return 1;
            break;
        }
        else if (ans == 2)
        {
            return 2;
            break;
        }
        else if (ans == 3)
        {
            return 3;
            break;
        }
        else
        {
            cout << "INVALID!! TRY AGAIN \n";
        }
    }
}

// Existing user function is to display the screen to the user who is an existing user, he gets option to login and move forward. 
void login::existing_user()
{       
    int ans,val;
    system("cls");
 
        while (1)
        {
            cout << "Welcome to the Existing user screen\n";
            cout << "Enter 1 to login :\n";
            cout << "Enter 2 to go back :\n";
            cin >> ans;
            if (ans == 1)
            {   
                while (true)
                {
                    cout << "Enter your ID\n";
                    cin >> ID;
                    cout << "Enter your password\n";
                    cin >> password;

                    if (idpass_check(ID, password))
                    {
                        cout << "The data is correct,login succesfull!!";
                        break;
                    }
                    else
                    {
                        cout << "Wrong details\n";
                    }
                }
                break;
            }
            else if(ans ==2)
            {
                Welcome(true);
                val = intro();
                if (val == 1)
                {
                    newuser();
                }
                else if (val == 2)
                {
                    existing_user();
                }
                else
                {
                    exit(0);
                }
                break;
            }
            else
            {
                cout << "INVALID ENTRY";
            }


        }


}

// newuser screen will be seen by the user when he presses 1 in the intro screen and here is where we will make him login 
void login::newuser()
{
    system("cls");
    int ans;
    while(1)
    {
        cout << "Welcome to the new login page :\n";
        cout << "Press 1 to go back to main screen :\n";
        cout << "Press 2 to Enter details:\n";
        cin >> ans;
        if (ans == 1)
        {
            Welcome(true);
            int val = intro();
            if (val == 1)
            {
                newuser();
            }
            else if (val == 2)
            {
                existing_user();
            }
            else
            {
                exit(0);
            }
            /*break;*/
        }
        else if (ans == 2)
        {
            cout << "Enter your details :\n";
            cout << "Enter your login ID:\n";
            cin >> ID;
            cout << "Enter your Password:\n";
            cin >> password;

            if (username_check(ID))
            {
                cout << "ERROR !!, choose a different ID";

            }
            else
            {
                /* cout << "Hello";*/
                if (register_user(ID, password))
                {
                    cout << "Successfull";
                }
                break;

            }
        }
        else
        {
            cout << "MAKE A VALID CHOICE :";
        }


    }

}

// This is a validation in which we check teh keyfield (login id ) to see that this is not taken by anyone 
bool login::username_check(const char* id)
{
    login l1;
    fstream f1;
    f1.open("player.dat", ios::in | ios::binary);
    while (f1.read((char*)&l1,sizeof(l1)))
    {
        if (strcmp(l1.ID,id) == 0)
        {
            return true;
        }

    }
    return false;
}

// This is main logic behind login, it checks the login id and password in the file and lets us forward only if both are correct
bool login::idpass_check(const char* id, const char* pass)
{
    login l1;
    fstream f1;
    f1.open("player.dat", ios::in | ios::binary);
    while (f1.read((char*)&l1, sizeof(l1)))
    {   
        if (strcmp(l1.ID, id) == 0)
        {
            if (strcmp(l1.password, pass) == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    return false;
}

// register user is called to register a user after specifiying that he has a unique login id and then dding it to our database
bool login::register_user(const char* id, const char* pass)
{
    login l1;
    strcpy_s(l1.ID,id);
    strcpy_s(l1.password,pass);
    fstream f1;
    l1.highest_score = 0;
    f1.open("player.dat", ios::app | ios::binary);
    f1.write((char*)&l1, sizeof(l1));
    f1.close();

    return true;

}

// Getter : getid is used to send the id to the main for future use 
char* login::getid()
{
    return ID;
}

// Getter : to send the current score of the user based on the input 
int login::getscore(const char* id)
{
    fstream f1;
    login l1;
    f1.open("player.dat", ios::in | ios::binary);
    while (!f1.eof())
    {
        f1.read((char*)&l1, sizeof(l1));
        if (strcmp(l1.ID, id) == 0)
        {
            return l1.highest_score;
        }

    }

    // exception handling
}

// Update score is a function to update user's score if he /she beats their currrent high score in the database file 
void login::update_score(int score,const char* id)
{
    fstream f1,f2;
    login l1,l2;
    f1.open("player.dat",ios::in | ios::binary);
    f2.open("Test.dat",ios::out | ios::binary);
    while (!f1.eof())
    {   
        f1.read((char*)&l1, sizeof(l1));
        if (strcmp(l1.ID,id) == 0)
        {   
            if(l1.highest_score<score)
            {   
                l2.highest_score = score;
                strcpy_s(l2.ID,l1.ID);
                strcpy_s(l2.password,l1.password);
                f2.write((char*)&l2, sizeof(l2));
            }
            else
            {
                l2.highest_score = l1.highest_score;
                strcpy_s(l2.ID, l1.ID);
                strcpy_s(l2.password, l1.password);
                f2.write((char*)&l2, sizeof(l2));
            }
        }
        else
        {
            f2.write((char*)&l2, sizeof(l2));
        }

    }

    f1.close();
    f2.close();
    remove("player.dat");
    int a = rename("Test.dat","player.dat");
}
