#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include"login.h"

using namespace std;
class post_game:public login 
{
public:
	int menu();
	void send_message(const char* id);
	void private_chat(char* cred);
	void direct_message(char* cred);
	void seechat();

};
