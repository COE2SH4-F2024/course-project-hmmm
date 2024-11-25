#include "GameMechs.h"
#include <stdio.h>

GameMechs::GameMechs() //initializes with default values for board size
{
    boardSizeX = 28; //only the size of the board that the snake can access, excludes borders
    boardSizeY = 13;
    score = 0;
    exitFlag = false;
    loseFlag = false;

    
    //this->food = objPos(rand() %boardSizeX, rand() %boardSizeY,'@'); //update to avoid snake tiles

}

GameMechs::GameMechs(int boardSizeX, int boardSizeY) //initializes with custom board size values
{
    this->boardSizeX = boardSizeX;
    this->boardSizeY = boardSizeY;
    score = 0;
    exitFlag = false;
    loseFlag = false;
    //this->food = objPos(rand() %boardSizeX, rand() %boardSizeY,'@'); //update to avoid snake tiles
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return this->exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return this->loseFlag;
}
    

char GameMechs::getInput() const
{
    return this->input;
}

int GameMechs::getScore() const
{
    return this->score;
}

void GameMechs::incrementScore()
{
    this->score++;
}

int GameMechs::getBoardSizeX() const
{
    return this->boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return this->boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    this->loseFlag = true;
}

void GameMechs::setInput(char input)
{
    this->input = input;
}

void GameMechs::clearInput()
{
    this->input = '\0';
}

// More methods should be added here