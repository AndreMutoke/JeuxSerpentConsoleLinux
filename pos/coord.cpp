#include "coord.h"

void initCoord(Coord *src)
{
    src->x = 0; src->y = 0;
}

void CopyCoord(Coord *src, Coord *dest)
{
    dest->x = src->x;
    dest->y = src->y;
}

void CreateCoord(int x, int y, Coord *coord1)
{
    coord1->x = x;
    coord1->y = y;
}

void permutCoord(Coord *coord1, Coord *coord2)
{
    Coord temp;
    initCoord(&temp);

    CopyCoord(coord1, &temp);
    CopyCoord(coord2, coord1);
    CopyCoord(&temp, coord2);
}
int compareCoords(Coord *coord1, Coord *coord2)
{
    int val = 0;
    
    if((coord1->x == coord2->x) && (coord1->y == coord2->y)) { val = 1;}
    
    return val;
}