#include "Food.h"
#include <time.h>
#include "objPos.h"
#include "objPosArrayList.h"


Food::Food(){
    foodPos = objPos(-1, -1, '&');
}

Food::~Food(){
    //TODO
    
}

objPos Food::getFoodPos() const
{
    return this->foodPos;
}


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

void Food::CoordsGeneration(int playerX, int playerY, Food* foodArray[]){
    srand(time(NULL));
    bool hasObject = false;
    int goodCoords = 0;
    do{
        hasObject = false;
        int x = rand()%28;
        int y = rand()%13;
        for(int i=0;i<5;i++){
            if((x == foodArray[i]->getFoodPos().pos->x && y == foodArray[i]->getFoodPos().pos->y)
                || (x==playerX && y==playerY)){
                hasObject = true;
            }

        }
        if(!hasObject){
            foodPos.pos->x = x;
            foodPos.pos->y = y;
            foodPos.symbol = 38;
            goodCoords++;
        }


    }while(goodCoords < 1);
}
