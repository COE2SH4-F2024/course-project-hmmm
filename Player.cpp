#include "Player.h"
#include "objPosArrayList.h"


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
    if(myDir != STOP){
        switch(myDir){
            case UP:
                if(playerPosList->getHeadElement().pos->y == 0)
                    playerPosList->getHeadElement().pos->y = mainGameMechsRef->getBoardSizeY() - 1;
                else
                    playerPosList->getHeadElement().pos->y--;
                break;
            case DOWN:
                if(playerPosList->getHeadElement().pos->y == mainGameMechsRef->getBoardSizeY() - 1)
                    playerPosList->getHeadElement().pos->y = 0;
                else
                    playerPosList->getHeadElement().pos->y++;
                break;
            case LEFT:
                if(playerPosList->getHeadElement().pos->x == 0)
                    playerPosList->getHeadElement().pos->x = mainGameMechsRef->getBoardSizeX() - 1;
                else
                    playerPosList->getHeadElement().pos->x--;
                break;
            case RIGHT:
                if(playerPosList->getHeadElement().pos->x == mainGameMechsRef->getBoardSizeX() - 1)
                    playerPosList->getHeadElement().pos->x = 0;
                else
                    playerPosList->getHeadElement().pos->x++;
                break;
        }
    }
}

bool Player::checkFoodConsumption(objPosArrayList* foodList){
    for(int i = 0; i < foodList->getSize(); i++){
        if(playerPosList->getHeadElement().pos->x == foodList->getElement(i).pos->x
           && playerPosList->getHeadElement().pos->y == foodList->getElement(i).pos->y){
                mainGameMechsRef->incrementScore();
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
//increase player length?
void Player::increasePlayerSize(bool wasFed){
    if(!wasFed){
        playerPosList->removeTail();
    }
}