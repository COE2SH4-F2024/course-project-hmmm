#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

#define DELAY_CONST 100000
#define FOOD_NUM_CONST 5

//Global Variables
bool exitFlag;
Player* player = nullptr;
GameMechs* gameMechs = nullptr;
objPosArrayList* playerList = nullptr;
objPosArrayList* foodList = nullptr;


Food* foodArray[FOOD_NUM_CONST] = {nullptr};

Food* food = nullptr;


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
    playerList = new objPosArrayList();
    playerList->insertHead(player->getPlayerPos());


    for(int i = 0; i < 5; i++){
        foodArray[i] = new Food();
    }
    for(int i = 0; i < 5; i++){
        foodArray[i]->CoordsGeneration(player->getPlayerPos().pos->x, player->getPlayerPos().pos->y, foodArray);
    }


    winningScore = 100;
    srand(time(NULL));
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

    player->updatePlayerDir();
    player->movePlayer();

    playerList->insertHead(player->getPlayerPos());
    bool collision = false;

    if(!collision){
        playerList->removeTail();
    }
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    bool hasObject = false;

    int i,j;
    for(i=0;i<gameMechs->getBoardSizeX()+2;i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
    for(i=0;i<gameMechs->getBoardSizeY();i++){
            MacUILib_printf("#");
        for(j=0; j<gameMechs->getBoardSizeX();j++){
            hasObject = false;


            for(int k = 0; k < playerList->getSize(); k++){
                if(j == (playerList->getElement(k).pos->x) && i == (playerList->getElement(k).pos->y)){
                    MacUILib_printf("%c", player->getPlayerPos().getSymbol());
                    hasObject = true;
                }
            }
            for(int k = 0; k < FOOD_NUM_CONST; k++){
                if(j == (foodArray[k]->getFoodPos().pos->x) && i == (foodArray[k]->getFoodPos().pos->y)){
                    MacUILib_printf("%c", foodArray[k]->getFoodPos().getSymbol());
                    hasObject = true;
                }
            }
            if(!hasObject){
                MacUILib_printf(" ");
            }
            
        }
        MacUILib_printf("#\n");
    }
    for(i=0;i<gameMechs->getBoardSizeX()+2;i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    free(player);
    free(gameMechs);
    //TODO for loop through array --> free(index)
    MacUILib_uninit();
}
