#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    //size of snake
    listSize = 0;

    //Size allocated
    arrayCapacity = 200;

    //arraylist containing nodes
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    //Destructor for objPosArrayList
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
        //Shift all elements to the right to accomodate room for the new head
        for (int i = listSize; i > 0; i--) {
            aList[i] = aList[i - 1];
        }

        //Set index 0 to the new head
        aList[0] = thisPos;
        listSize++;
    }
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //Inserts a new tail at the end of the list
    if (listSize < arrayCapacity) {
        aList[listSize] = thisPos;
        listSize++;
    }
}

void objPosArrayList::removeHead()
{
    //Shift all elements to the left
    for (int i = 0; i < listSize; i++) {
        aList[i] = aList[i + 1];
    }
}

void objPosArrayList::removeTail()
{
    //Removes the tail by setting it to null element and decreasing listSize
    aList[listSize - 1] = objPos();
    listSize--;
}

objPos objPosArrayList::getHeadElement() const
{
    //Returns the head element of the list
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    //Returns the tail element of the list
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
{
    //Returns the element at the specified index
    return aList[index];
}