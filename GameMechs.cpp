#include "GameMechs.h"
#include <stdio.h>

GameMechs::GameMechs() //initializes with default values for board size
{
    this->boardSizeX = 28; //only the size of the board that the snake can access, excludes borders
    this->boardSizeY = 13;
    this->score = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->food = objPos(rand() %boardSizeX, rand() %boardSizeY,'@'); //update to avoid snake tiles

}

GameMechs::GameMechs(int boardX, int boardY) //initializes with custom board size values
{
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->score = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    this->food = objPos(rand() %boardSizeX, rand() %boardSizeY,'@'); //update to avoid snake tiles
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

void GameMechs::setInput(char this_input)
{
    this->input = this_input;
}

void GameMechs::clearInput()
{
    this->input = '\0';
}

// More methods should be added here