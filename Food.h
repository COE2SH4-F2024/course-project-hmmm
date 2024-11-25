#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    private:
        int** takenCoords;
        int* chosenFoods;
        int x;
        int y;
        int type; //0 = normal, 1 = special_1, 2 = special_2

    public:
        Food();
        ~Food();
        int** CoordsGeneration(int playerX, int playerY);
        int* FoodGeneration();

};

#endif