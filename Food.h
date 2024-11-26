#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

class Food{
    private:
        objPosArrayList* foodPosList;

    public:
        Food();
        Food(int size);
        ~Food();
        void foodGeneration(objPosArrayList* playerPosList);
        //void FoodGeneration();

        objPosArrayList* getFoodPos() const;

};

#endif