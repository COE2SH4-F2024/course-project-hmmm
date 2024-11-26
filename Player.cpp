#include "Player.h"
#include "objPosArrayList.h"
#include "objPos.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(objPos(5,5,'@'));

    // more actions to be included
}

Player::~Player()
{
    //TODO delete any heap members here
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
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
    // PPA3 Finite State Machine logic
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
bool Player::checkFoodConsumption(objPosArrayList* foodList){
    for(int i = 0; i < foodList->getSize(); i++){
        if(playerPosList->getHeadElement().pos->x == foodList->getElement(i).pos->x
           && playerPosList->getHeadElement().pos->y == foodList->getElement(i).pos->y){
                if(foodList->getElement(i).getSymbol() == '%' && playerPosList->getSize() > 3){
                    //int halfSize = playerPosList->getSize()/2+1;
                    for(int j=0; j<3; j++){
                        playerPosList->removeTail();
                    }
                    mainGameMechsRef->incrementScore();
                }
                else if(foodList->getElement(i).getSymbol() == '$'){
                    for(int j=0; j<10; j++){
                        mainGameMechsRef->incrementScore();
                    }
                }
                else{
                    mainGameMechsRef->incrementScore();
                    
                }
                return true; 
                
           }
    }
    return false;
}
//TODO
void Player::checkSelfCollision(){
    for(int i = 2; i < playerPosList->getSize(); i++){
            if(playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y){
                mainGameMechsRef->setLoseFlag();
                mainGameMechsRef->setExitTrue();
                return;
            }
    }
    return;
}