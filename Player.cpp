#include "Player.h"
#include "objPosArrayList.h"
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    //Constructor for player class
    //Default direction is STOP
    //Player is placed at (14,6)
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(14,6,'@'));
}
Player::Player(GameMechs* thisGMRef, int x, int y)
{
    //Constructor for player class
    //Default direction is STOP
    //Player is placed at specified location
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(x,y,'@'));
}


Player::~Player()
{
    //Destructor for player class
    delete playerPosList;
    delete mainGameMechsRef;
    playerPosList = nullptr;
    mainGameMechsRef = nullptr;
}

objPosArrayList* Player::getPlayerPos() const
{
    //Return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    //Input processing logic for player direction
    switch(mainGameMechsRef->getInput()){                      
        case 'w':
            if(myDir != DOWN)
                myDir = UP;
            break;
        case 'a':
            if(myDir != RIGHT)
                myDir = LEFT;
            break;
        case 's':
            if(myDir != UP)
                myDir = DOWN;
            break;
        case 'd':
            if(myDir != LEFT)
                myDir = RIGHT;
            break;
    }
}

void Player::movePlayer()
{
    //Insert a head at the new position based on the direction
    switch(myDir){
        case UP:
            if(playerPosList->getHeadElement().pos->y == 0)
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x,mainGameMechsRef->getBoardSizeY() - 1,'@'));
            else
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x,playerPosList->getHeadElement().pos->y-1,'@'));
            break;


        case DOWN:
            if(playerPosList->getHeadElement().pos->y == mainGameMechsRef->getBoardSizeY() - 1)
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x, 0, '@'));
            else
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x, playerPosList->getHeadElement().pos->y + 1, '@'));
            break;
        

        case LEFT:
            if(playerPosList->getHeadElement().pos->x == 0)
                playerPosList->insertHead(objPos(mainGameMechsRef->getBoardSizeX() - 1, playerPosList->getHeadElement().pos->y, '@'));
            else
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x - 1, playerPosList->getHeadElement().pos->y, '@'));
            break;
        

        case RIGHT:
            if(playerPosList->getHeadElement().pos->x == mainGameMechsRef->getBoardSizeX() - 1)
                playerPosList->insertHead(objPos(0, playerPosList->getHeadElement().pos->y, '@'));
            else
                playerPosList->insertHead(objPos(playerPosList->getHeadElement().pos->x + 1, playerPosList->getHeadElement().pos->y, '@'));
            break;
        

        case STOP:
            playerPosList->insertHead(objPos(playerPosList->getHeadElement()));
            break;
    }
}

//& normal, %,$ special

//Check if the player has consumed food
bool Player::checkFoodConsumption(objPosArrayList* foodList){
    for(int i = 0; i < foodList->getSize(); i++){
        if(playerPosList->getHeadElement().pos->x == foodList->getElement(i).pos->x
        && playerPosList->getHeadElement().pos->y == foodList->getElement(i).pos->y){
                //Special food case --> % --> decrease player sive by 2
                if(foodList->getElement(i).getSymbol() == '%' && playerPosList->getSize() > 3){
                    for(int j=0; j<3; j++){
                        playerPosList->removeTail();
                    }
                    mainGameMechsRef->incrementScore();
                }
                
                //Special food case --> $ --> increase player score by 10
                else if(foodList->getElement(i).getSymbol() == '$'){
                    for(int j=0; j<10; j++){
                        mainGameMechsRef->incrementScore();
                    }
                }

                //Normal food case --> & --> increase player size by 1f
                else{
                    mainGameMechsRef->incrementScore();
                }

                return true;
           }
    }
    return false;
}


bool Player::checkSelfCollision(){
    //Loop through the player arraylist and check against head
    for(int i = 2; i < playerPosList->getSize(); i++){
        if(playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x
        && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y){

            //Update game end conditions
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return true;
        }
    }
    return false;
}