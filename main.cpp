#include<iostream>
#include"login.h"
#include<process.h>
#include<stdio.h>
#include"game.h"
#include"post_game.h"
#include<dos.h>
#include <cstdio>
#include <cstring>


using namespace std;


int main()
{  
    //////////////////////////////////////////  SECTION 1: LOGIN SYSTEM  ///////////////////////////////////////////////// 
   
    // Two variables to get return values.
    int ans, score;
    // boolean function to display snake 
    Welcome w(true);
    login l1;
    // normal menu for the beginning 
    ans = l1.intro();
    // caling differnt screens based on inputs namely existing and new user
    if (ans == 1)
    {   
        l1.newuser();
    }
    else if (ans == 2)
    {
        l1.existing_user();
    }
    else
    {
        exit(0);
    }
    //saving users id for future use.
    char* ID = l1.getid();
    score = l1.getscore(ID);

    ////////////////////////////////////////////  SECTION 2 : GAME PORTION  ///////////////////////////////////////////////
    
    ////random no. generation
    //srand((unsigned)time(NULL));

    //// object declared
    //snake snake;

    //// sending initial score.
    //snake.getscore(score);

    //// executing the game. 
    //snake.game_play();

    ////getting high score after game is over.
    //score = snake.send_high_score();

    //system("cls");
    //cout << "YOUR CURRENT HIGH SCORE IS\n" << score;

    //// update score in the file if the score is greater original score, i.e the user made a high score.
    //l1.update_score(score, ID);


    ////////////////////////////////////////////////// SECTION 3: POST GAME  //////////////////////////////////////////////////////
    int input;
    post_game p;

    // displaying menu to the user and calling require functions based on the inputs namely private chat, send message , see chat 
        input = p.menu();
        if (input == 1)
        {
            p.private_chat(ID);
        }
        else if (input == 2)
        {
            p.send_message(ID);
        }
        else if (input == 3)
        {
            p.seechat();
        }
        else if (input == 4)
        {
            exit(0);
        }

    

    return 1;

}