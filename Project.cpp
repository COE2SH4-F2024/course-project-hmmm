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
Food* food = nullptr;
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

    //creating new game objects
    gameMechs = new GameMechs();
    player = new Player(gameMechs);
    food = new Food(FOOD_NUM_CONST);
    food->foodGeneration(player->getPlayerPos());

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
    if(gameMechs->getScore() >= winningScore || gameMechs->getInput() == 27){
        gameMechs->setExitTrue();
    }
    exitFlag = gameMechs->getExitFlagStatus();
    if(gameMechs->getLoseFlagStatus() == false){
        player->updatePlayerDir();
        player->movePlayer();//adds a head
        if(player->checkFoodConsumption(food->getFoodPos())){
            food->foodGeneration(player->getPlayerPos());
        }else{
            player->getPlayerPos()->removeTail();
        }
        player->checkSelfCollision();
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
            for(int k = 0; k < player->getPlayerPos()->getSize(); k++){
                if(j == (player->getPlayerPos()->getElement(k).pos->x) && i == (player->getPlayerPos()->getElement(k).pos->y)){
                    MacUILib_printf("%c", player->getPlayerPos()->getElement(k).getSymbol());
                    hasObject = true;
                    break;
                }
            }
            for(int k = 0; k < FOOD_NUM_CONST; k++){
                if(j == (food->getFoodPos()->getElement(k).pos->x) && i == (food->getFoodPos()->getElement(k).pos->y)){
                    MacUILib_printf("%c", food->getFoodPos()->getElement(k).getSymbol());
                    hasObject = true;
                    break;
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
    MacUILib_printf("Score: %d\n",gameMechs->getScore());
    MacUILib_printf("WASD to Move, ESC to Shutdown\n");
    MacUILib_printf("The $ Special Food Gives You +10 Score\n");
    MacUILib_printf("The %% Special Food Acts Like Normal Food If You Have =<2 Length But Reduces Your Length By 2 When You Have >2 Length\n");


    if(gameMechs->getLoseFlagStatus() == true){
        MacUILib_printf("You Lose :(\n");
    }
    else if(gameMechs->getScore() >= 100 && gameMechs->getExitFlagStatus() == true){
        MacUILib_printf("You Win :)\n");
    }
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //MacUILib_clearScreen();    
    free(player);
    free(gameMechs);
    //TODO for loop through array --> free(index)
    MacUILib_uninit();
}
