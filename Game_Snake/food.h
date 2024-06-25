#ifndef FOOD_H
#define FOOD_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>

#include <vector>

#include "../board/board.h"
#include "../board/controlOutput.h"
#include "snake_game.h"

/// @brief La classe de la nourriture du serpent
class Food
{
public:

    /// @brief Le constructeur de la classe
    /// @param x Les paramètres en x
    /// @param y Paramètre en y
    /// @param frame Le tableau le conténant
    Food(int x = 0, int y = 0, Board *frame = NULL);

    /// @brief Changer la position de la nourriture
    void changeFoodPos(Coord *newCoord);

    /// @brief Générer aléatoirement la position
    /// @param borneY Limite en Y
    /// @param borneX Limite en X
    /// @param snakeEat Le serpent ayant manger
    /// @return COORD  la position nouvelle
    Coord aleaNumber(int borneY, int borneX, Snake *snakeEat=NULL);

    /// @brief Insérer la nourriture sur le plateau
    void setFoodToBoard();

    /// @brief Supprimer du plateau
    void clearFoodToBoard();

    /// @brief Récupère la position de la nourriture
    Coord getPosFood(){return this->posFood;}

private:

    /// @brief La position de la nourriture
    Coord posFood;

    /// @brief Le plateau contenant la nourriture
    Board *m_frameParent;

};

#endif // FOOD_H