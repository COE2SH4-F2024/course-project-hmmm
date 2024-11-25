#include "Food.h"

Food::Food(){
    takenCoords = new int*[5];
    for (int i=0;i<5;i++){
        takenCoords[i] = new int[2];
        takenCoords[i][0] = -1;
        takenCoords[i][1] = -1;
    }
}

Food::~Food(){
    for (int i=0;i<5;i++){
        delete takenCoords[i];
    }
    delete[] takenCoords;
    delete[] chosenFoods;
    takenCoords = NULL;
    chosenFoods = NULL;
}



int** Food::CoordsGeneration(int playerX, int playerY){
    int goodCoords = 0;
    do{
        x = rand()%28;
        y = rand()%13;
        for(int i=0;i<5;i++){
            if(x != takenCoords[i][0] && y != takenCoords[i][1] && x==playerX && y==playerY){
                takenCoords[i][0] = x;
                takenCoords[i][1] = y;
                goodCoords++;
            }
        }

    }while(goodCoords < 5);
    return takenCoords;
}

int* Food::FoodGeneration(){
    chosenFoods = new int[5];
    for(int i=0;i<5;i++){
        chosenFoods[i] = 0;
    }
    for(int i=0;i< rand()%3 ;i++){ // (max - min + 1) + 1 => (2 - 1 + 1)+ 1 either 1 or 2 special foods
        chosenFoods[i] = rand()% 3; //chooses a random special food (either type 1 or type 2)
    }
    return chosenFoods;
}