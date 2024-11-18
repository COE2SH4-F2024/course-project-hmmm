#include "GameMechs.h"

GameMechs::GameMechs()
{
    this->boardSizeX = 28; //only the size of the board that the snake can access, excludes borders
    this->boardSizeY = 13;
    this->score = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    //this->food = (random food generation code)

}

GameMechs::GameMechs(int boardX, int boardY)
{
    this->boardSizeX = boardX;
    this->boardSizeY = boardY;
    this->score = 0;
    this->exitFlag = false;
    this->loseFlag = false;
    //this->food = (random food generation code)
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
    this->exitFlag = true;
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