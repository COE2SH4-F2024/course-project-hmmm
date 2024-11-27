#include "objPos.h"

//Constructor for objPos class
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

//Overloaded constructor for objPos class taking custom coordinates and symbol as parameters
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Destructor for objPos class
objPos::~objPos(){
    delete pos;
}

//Copy Constructor for objPos class
objPos::objPos(const objPos& other){
    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;
}
//Copy Assignment Operator for objPos class
objPos& objPos::operator=(const objPos& other){
    this->~objPos();
    
    pos = new Pos;
    pos->x = other.pos->x;
    pos->y = other.pos->y;
    symbol = other.symbol;
}

//Copies using objPos
void objPos::setObjPos(objPos o){
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//Copies using parameter values
void objPos::setObjPos(int xPos, int yPos, char sym){
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

//Gets the position of an object
objPos objPos::getObjPos() const{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

//Gets the symbol of an object
char objPos::getSymbol() const{
    return symbol;
}

//Returns a boolean for whether two objects are occupying the same tile
bool objPos::isPosEqual(const objPos* refPos) const{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

//Gets the symbol if the positions of two objects is the same
char objPos::getSymbolIfPosEqual(const objPos* refPos) const{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
