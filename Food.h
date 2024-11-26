#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    private:
        objPos foodPos;

    public:
        Food();
        ~Food();
        void CoordsGeneration(int playerX, int playerY, Food* foodArray[]);
        void FoodGeneration(objPosArrayList foodList);

        objPos getFoodPos() const;

};

#endif