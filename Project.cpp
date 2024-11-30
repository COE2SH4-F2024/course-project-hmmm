#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "Food.h"
#include "objPosArrayList.h"

using namespace std;

//Constants
#define DELAY_CONST 100000
#define FOOD_NUM_CONST 5
#define WINNING_SCORE 100
#define BOARD_SIZE_X 28
#define BOARD_SIZE_Y 13

//Global Variables
bool exitFlag;
Player* player = nullptr;
Food* food = nullptr;
GameMechs* gameMechs = nullptr;



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

    //Creating new game objects
    gameMechs = new GameMechs(BOARD_SIZE_X, BOARD_SIZE_Y);
    player = new Player(gameMechs, BOARD_SIZE_X/2, BOARD_SIZE_Y/2);
    food = new Food(FOOD_NUM_CONST);

    //Initial generation of food
    food->foodGeneration(player->getPlayerPos(), FOOD_NUM_CONST);


    exitFlag = false;
}

void GetInput(void)
{
    //Obtain input from user
    gameMechs->clearInput();
    if(MacUILib_hasChar()){
        gameMechs->setInput(MacUILib_getChar());
    }
}

void RunLogic(void)
{
    //Check if the game is over
    if(gameMechs->getScore() >= WINNING_SCORE || gameMechs->getInput() == 27){
        gameMechs->setExitTrue();
    }
    exitFlag = gameMechs->getExitFlagStatus();

    //Update game logic
    if(gameMechs->getLoseFlagStatus() == false){
        player->updatePlayerDir();
        player->movePlayer();//Adds a head for player movement

        if(player->checkFoodConsumption(food->getFoodPos())){
            food->foodGeneration(player->getPlayerPos(), FOOD_NUM_CONST);
        }else if(!player->checkSelfCollision()){
            //Removes tail if no food is consumed and player did not collide with itself
            player->getPlayerPos()->removeTail();
        }
    }
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    //Is set to true if we print an object during a given iteration
    bool hasObject = false;

    //top boarder
    for(int i=0;i<gameMechs->getBoardSizeX()+2;i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    //i is y, j is x
    for(int i=0;i<gameMechs->getBoardSizeY();i++){
        //left boarder
        MacUILib_printf("#");

        //middle section
        for(int j=0; j<gameMechs->getBoardSizeX();j++){
            hasObject = false;

            //check if we have a player tile to print
            for(int k = 0; k < player->getPlayerPos()->getSize(); k++){
                if(j == (player->getPlayerPos()->getElement(k).pos->x) && i == (player->getPlayerPos()->getElement(k).pos->y)){
                    MacUILib_printf("%c", player->getPlayerPos()->getElement(k).getSymbol());
                    hasObject = true;
                    break;
                }
            }

            //check if we have a food tile to print
            for(int k = 0; k < FOOD_NUM_CONST; k++){
                if(j == (food->getFoodPos()->getElement(k).pos->x) && i == (food->getFoodPos()->getElement(k).pos->y)){
                    MacUILib_printf("%c", food->getFoodPos()->getElement(k).getSymbol());
                    hasObject = true;
                    break;
                }
            }

            //if no object is found, print a space
            if(!hasObject){
                MacUILib_printf(" ");
            }
        }

        //right boarder
        MacUILib_printf("#\n");
    }

    //bottom boarder
    for(int i=0;i<gameMechs->getBoardSizeX()+2;i++){
        MacUILib_printf("#");
    }
    MacUILib_printf("\n");

    //Print game information
    MacUILib_printf("Score: %d\n",gameMechs->getScore());
    MacUILib_printf("WASD to Move, ESC to Shutdown\n");
    MacUILib_printf("The $ Special Food Gives You +10 Score\n");
    MacUILib_printf("The %% Special Food Acts Like Normal Food If You Have =<2 Length But Reduces Your Length By 2 When You Have >2 Length\n");

    //Custom message for win/lose conditions
    if(gameMechs->getLoseFlagStatus() == true){
        MacUILib_printf("You Lose :(\n");
    }else if(gameMechs->getScore() >= WINNING_SCORE && gameMechs->getExitFlagStatus() == true){
        MacUILib_printf("You Win :)\n");
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    //Clean up memory
    delete player;
    delete food;
    delete gameMechs;
    MacUILib_uninit();
}
