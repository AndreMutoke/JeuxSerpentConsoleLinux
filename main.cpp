// pour compiler il faut : g++ -o output main.cpp fichier1.cpp fichier2.cpp
#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>

#include <vector>

#include "color/color.h"
#include "pos/coord.h"
#include "board/board.h"
#include "board/controlOutput.h"
#include "Game_Snake/snake_game.h"
#include "Game_Snake/food.h"

/// @brief Pour ne plus utiliser std::
using namespace std;

/// @brief Fonction qui sniffe le clavier ( Uniquement sur linux )
/// @return 1 ou 0 selon que le clavier est tapéou pas.
int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

/// @brief Foncton qui affiche le score
/// @param serp Le poiteur sur le serpent
void showScore(Snake *serp)
{
  int score = (serp->getLengthOfSnake()-1) * 10;
  cout<<"Score : "<<score<<endl;
}

/// @brief Fonction qui observe si le condition de fin de jeux sont remplies
/// @param game l'état du jeux
/// @param serpent Le pointeur du serpent
void CasdeGameOver(int *game, Snake *serpent)
{
  Coord positionTete = serpent->getHeadSnakePos();
  for(int i=1; i<serpent->getLengthOfSnake(); ++i)
  {
    Coord testCoord = serpent->getPartSnakePos(i);
    if( compareCoords(&testCoord, &positionTete)) { *game = 1; return;}
  }

}

/// @brief Fonction pricipale du programme
/// @return INT 0 fin du programme
int main()
{ 
    system("clear"); int gameOver = 0;

    int tour = 0; long delayframe = 150000;
    Coord posBoard; initCoord(&posBoard);
    Board *tableau = new Board(70, 35, &posBoard);

    Snake *serpent = new Snake(1, 1, tableau);// (ligne, colonne) (x, y)
    Food *SnakeFood = new Food(14, 16, tableau);
    // serpent->makeSnake();
    // tc_clear_screen();
     

    while(!gameOver)
    {
      usleep(delayframe);
      tableau->Show();
      if(kbhit())
      {
        switch (getchar())
        {
        case 'w':
          Coord c1; initCoord(&c1); Coord c2; initCoord(&c2);
          c1 = serpent->nextMoveUp(); c2 = SnakeFood->getPosFood();
          if( compareCoords(&c1, &c2) )
          {
            SnakeFood->clearFoodToBoard();
            serpent->grandi();
            Coord nouveCoord = SnakeFood->aleaNumber(tableau->getWidthBoard() - 1, tableau->getHeightBoard() - 2, serpent);
            SnakeFood->changeFoodPos(&nouveCoord);
            SnakeFood->setFoodToBoard();
          }
          serpent->moveUp(); serpent->changeDirection('u'); serpent->checkPositionInterdit(&gameOver); CasdeGameOver(&gameOver, serpent);
          break;

        case 's':
          Coord c3; initCoord(&c3); Coord c4; initCoord(&c4);
          c3 = serpent->nextMoveDown(); c4 = SnakeFood->getPosFood();
          if( compareCoords(&c3, &c4) )
          {
            SnakeFood->clearFoodToBoard();
            serpent->grandi();
            Coord nouveCoord = SnakeFood->aleaNumber(tableau->getWidthBoard() - 1, tableau->getHeightBoard() - 2, serpent);
            SnakeFood->changeFoodPos(&nouveCoord);
            SnakeFood->setFoodToBoard();
          }
          serpent->moveDown(); serpent->changeDirection('d'); serpent->checkPositionInterdit(&gameOver); CasdeGameOver(&gameOver, serpent);
          break;

        case 'd':
          Coord c5; initCoord(&c5); Coord c6; initCoord(&c6);
          c5 = serpent->nextMoveRight(); c6 = SnakeFood->getPosFood();
          if( compareCoords(&c5, &c6) )
          {
            SnakeFood->clearFoodToBoard();
            serpent->grandi();
            Coord nouveCoord = SnakeFood->aleaNumber(tableau->getWidthBoard() - 1, tableau->getHeightBoard() - 2, serpent);
            SnakeFood->changeFoodPos(&nouveCoord);
            SnakeFood->setFoodToBoard();
          }
          serpent->moveRight(); serpent->changeDirection('r'); serpent->checkPositionInterdit(&gameOver); CasdeGameOver(&gameOver, serpent);
          break;

        case 'a':
          Coord c7; initCoord(&c7); Coord c8; initCoord(&c8);
          c7 = serpent->nextMoveLeft(); c8 = SnakeFood->getPosFood();
          if( compareCoords(&c7, &c8) )
          {
            SnakeFood->clearFoodToBoard();
            serpent->grandi();
            Coord nouveCoord = SnakeFood->aleaNumber(tableau->getWidthBoard() - 1, tableau->getHeightBoard() - 2, serpent);
            SnakeFood->changeFoodPos(&nouveCoord);
            SnakeFood->setFoodToBoard();
          }
          serpent->moveLeft(); serpent->changeDirection('l'); serpent->checkPositionInterdit(&gameOver); CasdeGameOver(&gameOver, serpent);
          break;
        case 'p':
          gameOver = 1;
          break;
        
        }
      }
      else{
        Coord co7; initCoord(&co7); Coord co8; initCoord(&co8);
        co7 = serpent->nextMoving(); co8 = SnakeFood->getPosFood();
        if( compareCoords(&co7, &co8) )
        {
          SnakeFood->clearFoodToBoard();
          serpent->grandi();
          Coord nouveCoord = SnakeFood->aleaNumber(tableau->getWidthBoard() - 1, tableau->getHeightBoard() - 2, serpent);
          SnakeFood->changeFoodPos(&nouveCoord);
          SnakeFood->setFoodToBoard();
          }
        serpent->moving(); serpent->checkPositionInterdit(&gameOver); CasdeGameOver(&gameOver, serpent);
      }
      if(tour == 0 && (serpent->getLengthOfSnake() %10  == 0)){delayframe = delayframe/2; tour =1;}
      showScore(serpent);
      tc_move_cursor(0,0);
    }
    return 0;
}
