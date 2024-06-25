#include "food.h"

Food::Food(int x, int y, Board *frame)
{
    initCoord(&this->posFood);
    CreateCoord(x, y, &this->posFood);

    this->m_frameParent = frame;
    this->setFoodToBoard();
}

void Food::changeFoodPos(Coord *newCoord)
{
    this->posFood.x = newCoord->x;
    this->posFood.y = newCoord->y;
}

void Food::setFoodToBoard()
{
    
    this->m_frameParent->setElement(&this->posFood, '$');
    
}

void Food::clearFoodToBoard()
{ 
    this->m_frameParent->setElement(&this->posFood, ' ');
}
Coord Food::aleaNumber(int borneY, int borneX, Snake *snakeEat)
{
    srand((unsigned int)time(0));
    int  x = rand()%borneX ;
    int y = rand()%borneY;
    Coord coordS; initCoord(&coordS); 
    CreateCoord(x, y, &coordS);
    for(int i=0; i<snakeEat->getLengthOfSnake(); ++i)
    {
        Coord crd1; initCoord(&crd1); crd1 = snakeEat->getPartSnakePos(i);
        if( !compareCoords(&crd1, &coordS))
        {
            if( (x != 0) && (y != 0) ) {return coordS;}
            
        }
        int  x = rand()%borneX ;
        int y = rand()%borneY;
        CreateCoord(x, y, &coordS);
    }

    initCoord(&coordS);
    return coordS;

}