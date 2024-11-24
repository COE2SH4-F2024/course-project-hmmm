#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPos = objPos(5,5,'@');

    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
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
                if(playerPos.pos->y == 0)
                    playerPos.pos->y = mainGameMechsRef->getBoardSizeY() - 1;
                else
                    playerPos.pos->y--;
                break;
            case DOWN:
                if(playerPos.pos->y == mainGameMechsRef->getBoardSizeY() - 1)
                    playerPos.pos->y = 0;
                else
                    playerPos.pos->y++;
                break;
            case LEFT:
                if(playerPos.pos->x == 0)
                    playerPos.pos->x = mainGameMechsRef->getBoardSizeX() - 1;
                else
                    playerPos.pos->x--;
                break;
            case RIGHT:
                if(playerPos.pos->x == mainGameMechsRef->getBoardSizeX() - 1)
                    playerPos.pos->x = 0;
                else
                    playerPos.pos->x++;
                break;
        }
    }
}

// More methods to be added
