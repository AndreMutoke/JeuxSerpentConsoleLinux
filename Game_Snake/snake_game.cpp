#include "snake_game.h"
#include "../board/controlOutput.h"

Snake::Snake(int x, int y, Board *frame)
{
    initCoord(&this->posSnake);
    CreateCoord(y, x, &this->posSnake);
    this->m_direction = 'n';
    this->m_velocity = 1;
    
    this->m_frameParent = frame;
    this->createHead();
    
}

// void Snake::game()
// {
//     switch (this->kbhit())
//     {
//     case 'w':
//         usleep(100000);
//         this->moveUp();
//         break;
//     case 's':
//         usleep(100000);
//         this->moveDown();
//         break;
//     case 'a':
//         usleep(100000);
//         this->moveLeft();
//         break;
//     case 'd':
//         usleep(100000);
//         this->moveRight();
//         break;
//     }
// }

void Snake::changePosofSnake(Coord *newCoordHead)
{

    for(int i=0; i < (int) this->the_snake.size(); ++i)
    {
        Coord c1 = this->the_snake[0].getPosBoard();
        Coord c2 = this->the_snake[i].getPosBoard();

        this->the_snake[i].setPosBoard(&c1);
        this->the_snake[0].setPosBoard(&c2);
    }

    this->the_snake[0].setPosBoard(newCoordHead);
}

void Snake::putSnakeToBoard()
{

    for(int i= 0; i < (int)this->the_snake.size(); ++i)
    {
        Coord posOfSnake = this->the_snake[i].getPosBoard();
        this->m_frameParent->setElement(&posOfSnake, '0');
    }

}

void Snake::clearSnakeToBoard()
{
    for(int i= 0; i < (int) this->the_snake.size(); ++i)
    {
        Coord posOfSnake = this->the_snake[i].getPosBoard();
        this->m_frameParent->setElement(&posOfSnake, ' ');
    }
}

void Snake::createHead()
{
    // Coord tempPos; initCoord(&tempPos);
    // CreateCoord(23, 23, &tempPos);
    Cell headSnake(1, 1, &this->posSnake);

    this->the_snake.push_back(headSnake);
    this->makeSnakeHead();
}
void Snake::grandi()
{
    int x = this->the_snake[the_snake.size() - 1].getPosBoard().x ;
    int y = this->the_snake[the_snake.size() - 1].getPosBoard().y + 1;

    Coord newCoord; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    Coord lastCoord; initCoord(&lastCoord);
    lastCoord = this->the_snake[the_snake.size() - 1].getPosBoard();

    if(compareCoords(&newCoord, &lastCoord))
    {
        int y = this->the_snake[the_snake.size() - 1].getPosBoard().y - 1;
        initCoord(&newCoord); CreateCoord(x, y, &newCoord);
    }
    
    Cell bodySnake(1, 1, &newCoord);
    this->the_snake.push_back(bodySnake);
    this->m_frameParent->setElement(&newCoord, '0');
}

void Snake::moveUp()
{

    int x= this->the_snake[0].getPosBoard().x - this->m_velocity;
    int y = this->the_snake[0].getPosBoard().y;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    this->clearSnakeToBoard();
    this->changePosofSnake(&newCoord);
    this->putSnakeToBoard();

    // Coord lastCoord = this->the_snake[0].getPosBoard();
    // for(int i=0; i<this->the_snake.size(); ++i)
    // {
    //     if(this->the_snake.size() > 1)
    //     {
        
    //         if(i>0 && i<the_snake.size()-1)
    //         {
    //             Coord c1 = this->the_snake[0].getPosBoard();
    //             Coord c2 = this->the_snake[i].getPosBoard();

    //             this->the_snake[i].setPosBoard(&c1);
    //             this->the_snake[0].setPosBoard(&c2);

    //             this->the_snake[i].setElement(&c1, 'o');

    //             // permutCoord(&this->the_snake[0].getPosBoard(), &this->the_snake[i].getPosBoard());
    //         }
    //         else if(i == the_snake.size()-1)
    //         {
    //             // permutCoord(&this->the_snake[0].getPosBoard(), &this->the_snake[i].getPosBoard());
    //             Coord c1 = this->the_snake[0].getPosBoard();
    //             Coord c2 = this->the_snake[i].getPosBoard();

    //             this->the_snake[i].setPosBoard(&c1);

    //             int x= lastCoord.x-1;
    //             int y = lastCoord.y;
    //             Coord newCoord ; initCoord(&newCoord);
    //             CreateCoord(x, y, &newCoord);
    //             this->the_snake[0].setPosBoard(&newCoord);

    //             // this->m_frameParent->setElement(&c2, ' ');                
    //         }
            
    //     }
    //     else if(this->the_snake.size() == 1)
    //     {
    //         int x= this->the_snake[0].getPosBoard().x - 1;
    //         int y = this->the_snake[0].getPosBoard().y;
    //         Coord newCoord ; initCoord(&newCoord);

    //         CreateCoord(x, y, &newCoord);
    //         this->the_snake[0].setPosBoard(&newCoord);

    //         this->m_frameParent->setElement(&lastCoord, ' ');
    //         this->m_frameParent->setElement(&newCoord, '0');
    //     }
        

    // }
    
}
Coord Snake::nextMoveUp()
{
    int x= this->the_snake[0].getPosBoard().x - this->m_velocity;
    int y = this->the_snake[0].getPosBoard().y;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    return newCoord;
}

void Snake::moveRight()
{
    int x= this->the_snake[0].getPosBoard().x;
    int y = this->the_snake[0].getPosBoard().y + this->m_velocity;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    this->clearSnakeToBoard();
    this->changePosofSnake(&newCoord);
    this->putSnakeToBoard();
}
Coord Snake::nextMoveRight()
{
    int x= this->the_snake[0].getPosBoard().x;
    int y = this->the_snake[0].getPosBoard().y + this->m_velocity;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    return newCoord;
}

void Snake::moveDown()
{
    int x= this->the_snake[0].getPosBoard().x + this->m_velocity;
    int y = this->the_snake[0].getPosBoard().y;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    this->clearSnakeToBoard();
    this->changePosofSnake(&newCoord);
    this->putSnakeToBoard();
}
Coord Snake::nextMoveDown()
{
    int x= this->the_snake[0].getPosBoard().x + this->m_velocity;
    int y = this->the_snake[0].getPosBoard().y;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    return newCoord;
}
void Snake::moveLeft()
{
    int x= this->the_snake[0].getPosBoard().x;
    int y = this->the_snake[0].getPosBoard().y - this->m_velocity;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    this->clearSnakeToBoard();
    this->changePosofSnake(&newCoord);
    this->putSnakeToBoard();
}
Coord Snake::nextMoveLeft()
{
    int x= this->the_snake[0].getPosBoard().x;
    int y = this->the_snake[0].getPosBoard().y - this->m_velocity;
    Coord newCoord ; initCoord(&newCoord);
    CreateCoord(x, y, &newCoord);
    return newCoord;
}

void Snake::makeSnakeHead()
{
    this->m_frameParent->setElement(&this->posSnake, '0');
}

void Snake::moving()
{
    switch (this->m_direction)
    {
    case 'u':
         moveUp();
        //  this->changeDirection(d);
        break;
    case 'd':
         moveDown();
        //  this->changeDirection(d);
        break;
    case 'l':
        moveLeft();
        // this->changeDirection(d);
        break;
    case 'r':
        moveRight();
        // this->changeDirection(d);
        break;
    case 'n':
        // this->changeDirection(d);// moveUp();
        break;
    }
}
Coord Snake::nextMoving()
{
    Coord newCoord ; initCoord(&newCoord);
    int x=0; int y =0;
    switch (this->m_direction)
    {
    case 'u':
        x = this->the_snake[0].getPosBoard().x - this->m_velocity;
        y = this->the_snake[0].getPosBoard().y;
        
        CreateCoord(x, y, &newCoord);
        break;
    case 'd':
        x= this->the_snake[0].getPosBoard().x + this->m_velocity;
        y = this->the_snake[0].getPosBoard().y;
        CreateCoord(x, y, &newCoord);
        break;
    case 'l':
        x= this->the_snake[0].getPosBoard().x;
        y = this->the_snake[0].getPosBoard().y - this->m_velocity;
        CreateCoord(x, y, &newCoord);
        break;
    case 'r':
        x= this->the_snake[0].getPosBoard().x;
        y = this->the_snake[0].getPosBoard().y + this->m_velocity;
        
        CreateCoord(x, y, &newCoord);
        break;
    case 'n':
        
        break;
    }
    return newCoord;
}
void Snake::checkPositionInterdit(int *game)
{
    int x = this->the_snake[0].getPosBoard().x;
    int y = this->the_snake[0].getPosBoard().y;

    if((x == this->m_frameParent->getHeightBoard() -1) || (y == this->m_frameParent->getWidthBoard() -1))
    {
        *game = 1;
    }
    if((x == 0) || (y == 0))
    {
        *game = 1;
    }


}

