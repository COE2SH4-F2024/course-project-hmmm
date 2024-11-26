#include "Food.h"
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"


Food::Food(){
    foodPosList = new objPosArrayList();
    for(int i = 0; i < 5; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }
}
Food::Food(int size){
    foodPosList = new objPosArrayList();
    for(int i = 0; i < size; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }
}

Food::~Food(){
    //TODO
    
}

objPosArrayList* Food::getFoodPos() const
{
    return foodPosList;
}


void Food::foodGeneration(objPosArrayList* playerPosList){
    delete foodPosList;
    foodPosList = new objPosArrayList();
    for(int i = 0; i < 5; i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }

    srand(time(NULL));
    bool hasObject = false;
    int goodCoords = 0;
    int numSpecial = (rand()% (2)+1);
    do{
        hasObject = false;
        int x = rand()%28;
        int y = rand()%13;
        for(int i=0;i<foodPosList->getSize();i++){
            if(x == foodPosList->getElement(i).pos->x && y == foodPosList->getElement(i).pos->y){
                hasObject = true;
            }
        }
        for(int i = 0; i < playerPosList->getSize(); i++){
            if(x == playerPosList->getElement(i).pos->x && y == playerPosList->getElement(i).pos->y){
                hasObject = true;
            }
        }
        
        if(!hasObject && goodCoords<numSpecial){
            char chosenSpecial = (rand()% (2)) + 36;
            foodPosList->insertHead(objPos(x,y,chosenSpecial));
            foodPosList->removeTail();
            goodCoords++;
        }
        else if(!hasObject && goodCoords >= numSpecial){
            foodPosList->insertHead(objPos(x,y,38));
            foodPosList->removeTail();
            goodCoords++;
        }

    }while(goodCoords < foodPosList->getSize());
}


