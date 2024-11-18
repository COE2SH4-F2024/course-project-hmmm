#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;

#define DELAY_CONST 100000

//Global Variables
bool exitFlag;
Player* player = nullptr;
GameMechs* gameMechs = nullptr;

int winningScore;



void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    //creating new gamne objects
    gameMechs = new GameMechs();
    player = new Player(gameMechs);
    winningScore = 100;

    exitFlag = false;
}

void GetInput(void)
{
    gameMechs->clearInput();
    if(MacUILib_hasChar()){
        gameMechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    if(gameMechs->getScore() == winningScore || gameMechs->getInput() == 27){
        gameMechs->setExitTrue();
    }
    exitFlag = gameMechs->getExitFlagStatus();


}

void DrawScreen(void)
{
    MacUILib_clearScreen();
        int hasObject = 0;

    MacUILib_clearScreen();
    MacUILib_printf("####################\n");
    MacUILib_printf("####################\n");
    char input = gameMechs->getInput();

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
