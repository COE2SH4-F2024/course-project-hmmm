#include "GameMechs.h"
#include <stdio.h>

//Initializes with default values for board size
GameMechs::GameMechs()
{
    //Initializes only the size of the board that the snake can access, excludes borders
    boardSizeX = 28;
    boardSizeY = 13;
    score = 0;
    exitFlag = false;
    loseFlag = false;
}

//Initializes with custom values for board size
GameMechs::GameMechs(int boardSizeX, int boardSizeY) 
{
    this->boardSizeX = boardSizeX;
    this->boardSizeY = boardSizeY;
    score = 0;
    exitFlag = false;
    loseFlag = false;
}

//Destructor
GameMechs::~GameMechs()
{
    //TODO
}

//Gets the status of the exit flag
bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

//Gets the lose flag status
bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    
//Gets player input
char GameMechs::getInput() const
{
    return input;
}

//Gets the current score
int GameMechs::getScore() const
{
    return score;
}

//Increases score by 1
void GameMechs::incrementScore()
{
    score++;
}

//Gets the X size of the board
int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

//Gets the Y size of the board
int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}

//Sets the exit condition to true
void GameMechs::setExitTrue()
{
    exitFlag = true;
}

//Sets the lose flag to true
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

//Sets the this->input to parameter input
void GameMechs::setInput(char input)
{
    this->input = input;
}

//Clears the input
void GameMechs::clearInput()
{
    input = '\0';
}