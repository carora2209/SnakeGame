#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

class Welcome
{
private:
    bool start;
public:
    Welcome(const bool input);

};

class login
{
protected:
    char ID[100];
    char password[100];
    int highest_score;
public:
    void existing_user();
    int intro();
    void newuser();
    bool idpass_check(const char* id, const char* pass);
    bool username_check(const char* id);
    bool register_user(const char* id, const char* pass);
    char* getid();
    int getscore(const char* id);   
    void update_score(int score,const char* id);

};

