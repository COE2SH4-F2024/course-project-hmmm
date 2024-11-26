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

//TODO BONUS SPECIAL FRUIT
// void Food::FoodGeneration(objPosArrayList foodList){
//     srand(time(NULL));
//     chosenFoods = new int[5];
//     // for(int i=0;i<5;i++){
//     //     chosenFoods[i] = 40;
//     // }
//     for(int i=0;i< rand()%3 ;i++){ // (max - min + 1) + 1 => (2 - 1 + 1)+ 1 either 1 or 2 special foods
//         chosenFoods[i] = rand()% 3 + 36; //chooses a random special food (either type 1 or type 2)
//     }//generates between 1 and 2 inclusive so either 1 or 2
// }

void Food::foodGeneration(objPosArrayList* playerPosList){
    //delete food arrayList
    delete foodPosList;
    foodPosList = new objPosArrayList();
    for(int i = 0; i < foodPosList->getSize(); i++){
        foodPosList->insertHead(objPos(-1, -1, '&'));
    }

    srand(time(NULL));
    bool hasObject = false;
    int goodCoords = 0;
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
        if(!hasObject){
            foodPosList->insertHead(objPos(x,y,38));
            goodCoords++;
        }

    }while(goodCoords < foodPosList->getSize());
}
