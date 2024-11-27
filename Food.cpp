#include "Food.h"
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"

//Constructor for Food class
//Creates an array list foodPosList with 5 food items
Food::Food(){
    foodPosList = new objPosArrayList();
    for(int i = 0; i < 5; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }
}

//Overloaded constructor for Food class
//Creates an array list foodPosList with parameter size number of food items
Food::Food(int size){
    foodPosList = new objPosArrayList();
    for(int i = 0; i < size; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }
}

//Food destructor
Food::~Food(){
    delete foodPosList;
}

//Returns array list foodPosList
objPosArrayList* Food::getFoodPos() const
{
    return foodPosList;
}


void Food::foodGeneration(objPosArrayList* playerPosList, int numFood){
    delete foodPosList;
    //Creates and initializes new foodPosList
    foodPosList = new objPosArrayList();
    for(int i = 0; i < numFood; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }

    //Seeds rand
    srand(time(NULL));
    bool hasObject = false;
    int goodCoords = 0;
    //Initializes numSpecial to be 1 or 2 using rand
    int numSpecial = (rand()% (2)+1);
    //Generates random unoccupied coordinates and special foods to be stored in foodPosList
    //Loops while not all foods have been assigned random, non-overlapping coordinates
    do{
        hasObject = false;
        int x = rand()%28;
        int y = rand()%13;
        //Checks if random x,y coordinate overlaps with any existing foods
        for(int i=0;i<foodPosList->getSize();i++){
            if(x == foodPosList->getElement(i).pos->x && y == foodPosList->getElement(i).pos->y){
                hasObject = true;
            }
        }

        //Checks if random x,y coordinate overlaps with any tile occupied by the player
        for(int i = 0; i < playerPosList->getSize(); i++){
            if(x == playerPosList->getElement(i).pos->x && y == playerPosList->getElement(i).pos->y){
                hasObject = true;
            }
        }
        
        //Generates either 1 or 2 special foods and assigns them a random coordinate
        if(!hasObject && goodCoords<numSpecial){
            char chosenSpecial = (rand()% (2)) + 36;
            foodPosList->insertHead(objPos(x,y,chosenSpecial));
            foodPosList->removeTail();
            goodCoords++;
        }

        //Makes the rest of the foods (either 3 or 4) of the normal food type and assigns them a random coordinate
        else if(!hasObject && goodCoords >= numSpecial){
            foodPosList->insertHead(objPos(x,y,38));
            foodPosList->removeTail();
            goodCoords++;
        }

    }while(goodCoords < foodPosList->getSize());
}


