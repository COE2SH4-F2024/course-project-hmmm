#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //size of snake
    listSize = 0;

    //size allocated
    arrayCapacity = 200;

    //arraylist containing nodes
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
    aList = nullptr;
    listSize = 0;
    arrayCapacity = 0;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize < arrayCapacity) {
        //Shift all elements to the right
        for (int i = listSize; i > 0; i--) {
            aList[i] = aList[i - 1];
        }
        aList[0] = thisPos;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize < arrayCapacity) {
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    for (int i = 0; i < listSize; i++) {
        aList[i] = aList[i + 1];
    }
}

void objPosArrayList::removeTail()
{
    aList[listSize - 1] = objPos();
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}