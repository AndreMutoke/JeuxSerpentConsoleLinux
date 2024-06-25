#include "color.h"

void initColor(color *src)
{
    src->r = 0;
    src->v = 0;
    src->b = 0;
}

void createColor(int r, int v, int b, color *clr)
{
    clr->r = r;
    clr->v = v;
    clr->b = b;
}

void ColorCopy(color *clrsrc, color *clrdest)
{
    clrdest->r = clrsrc->r; 
    clrdest->v = clrsrc->v;
    clrdest->b = clrsrc->b;
}

void permutColor(color *clr1, color *clr2)
{
    color temp;
    initColor(&temp);

    ColorCopy(clr1, &temp);
    ColorCopy(clr2, clr1);
    ColorCopy(&temp, clr2);

}
