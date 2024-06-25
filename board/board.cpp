#include "board.h"
#include "controlOutput.h"

#include <string>

#define MAX_SCREEN_WIDTH 240
#define MAX_SCREEN_HEIGTH 320



Board::Board(int w, int h, Coord *pos)
{
    Board::m_width = w;
    Board::m_height = h;
    CopyCoord(pos, &this->posBoard);
    initMap(); initElements();

}

Board::Board(int w , int h)
{
    Board::m_width = w;
    Board::m_height = h; 
    Coord centerCoord = this->centerBoard(MAX_SCREEN_WIDTH, MAX_SCREEN_HEIGTH);
    CopyCoord(&centerCoord, &this->posBoard);
    initMap();

}

void Board::Show()
{
    
   this->defineBoard();

   
}

void Board::setPixelColor(Coord *coord1, color *clr1)
{
    int x = coord1->x;
    int y = coord1->y;
    ColorCopy(clr1, &this->pixelBoard[x][y]);
}

void Board::setElement(Coord *coord1, char elmnt)
{
    int x = coord1->x;
    int y = coord1->y;
    this->element[x][y] = elmnt;    
}


Coord Board::centerBoard(int wScreen, int hScreen)
{
    int xpos= wScreen/2; int ypos = hScreen/2;
    Coord temp; initCoord(&temp);
    CreateCoord(xpos, ypos, &temp);

    return temp;
}

void Board::defineBoard(void)
{
    std::cout<<TC_BG_BLU;
    std::cout<<TC_WTH;
    for(int i=0; i<this->m_width; ++i){std::cout<<"#";}
    std::cout<<"##";
    std::cout<<"\n";

    for(int i=0; i<this->m_height; ++i)
    {
            for(int j=0; j<this->m_width; ++j)
            {
                if(j>0 && j<this->m_width-1)
                {
                    
                    std::cout<<this->element[i][j];
                }
                else
                {
                    if(j==0) {std::cout<<"#"; std::cout<<this->element[i][j];}
                    if(j==this->m_width-1) {std::cout<<"#";}
                }
                
            }
            std::cout<<"\n";
    }
    for(int i=0; i<this->m_width; ++i){std::cout<<"#";}
    std::cout<<"##";
    std::cout<<"\n";
        
    std::cout<<TC_BG_NRM;
    std::cout<<TC_NRM;

}

void Board::initMap(void)
{
    std::vector<color> row;

    for(int i=0; i < (int) this->m_width; ++i)
    {
        color temp; initColor(&temp);
        row.push_back(temp);
    } // On a fini a remplir tout les colonnes, maintenant on s'occupe de la ligne

    for(int i=0; i<this->m_height; ++i)
    {
        pixelBoard.push_back(row);
    }
}

void Board::initElements()
{
    std::vector<char> row;

    for(int i=0; i < (int) this->m_width; ++i)
    {
        char temp = ' '; 
        row.push_back(temp);
    } // On a fini a remplir tout les colonnes, maintenant on s'occupe de la ligne

    for(int i=0; i < (int) this->m_height; ++i)
    {
        this->element.push_back(row);
    }

}
