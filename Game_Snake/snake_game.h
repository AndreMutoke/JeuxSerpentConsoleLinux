#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>

#include <vector>

#include "../board/board.h"


/// @brief La classe su serpent
class Snake
{
public:
    /// @brief Le constructeur du serpent
    /// @param x Les coordonnées en x du serpent
    /// @param y Les coordonnées en y du serpent
    /// @param frame Le plateau
    Snake(int x = 0, int y = 0, Board *frame = NULL);

    /// @brief Insérer le serpent à une position
    /// @param coord1 La nouvelle position du serpent
    void setSnakeCoord(Coord *coord1){
        int x = coord1->x;
        int y = coord1->y;

        CreateCoord(x, y, &this->posSnake);

    }

    /// @brief Chercher la t\^ete du serpent
    /// @return Les coordonnées de la position de la t\^ete du serpent
    Coord getHeadSnakePos(){return this->the_snake[0].getPosBoard();}

    /// @brief Récuperer la longueur du serpent
    /// @return La longueur
    int getLengthOfSnake(){return this->the_snake.size();}

    /// @brief La position d'une partie du serpent
    /// @param pos L'élément
    /// @return La position
    Coord getPartSnakePos(int pos){return this->the_snake[pos].getPosBoard();}
    
    /// @brief Changer la position d'élément du serpent
    /// @param newCoordHead Les nouvelles positions
    void changePosofSnake(Coord *newCoordHead);

    /// @brief Insérer le serpent dans le tableau
    void putSnakeToBoard();

    /// @brief Supprimmer Le serpent du tableau
    void clearSnakeToBoard();

    /// @brief Insérer la t\^ete du serpent
    void makeSnakeHead();

    /// @brief Déplacement du serpent
    void moving();

    /// @brief vérification de la position future
    /// @return La position futur
    Coord nextMoving();

    /// @brief Déplacement d'en haut
    void moveUp();

    /// @brief La position futur d'en haut
    /// @return La position futur d'en haut
    Coord nextMoveUp();

    /// @brief Déplacement à droite
    void moveRight();

    /// @brief Position future de droite
    /// @return Position futur de droite
    Coord nextMoveRight();

    /// @brief Deplacement en bas
    void moveDown();

    /// @brief Déplacement future en bas
    /// @return Déplacement future en bas
    Coord nextMoveDown();

    /// @brief Déplacement de gauche
    void moveLeft();

    /// @brief Déplacement future de gauche
    /// @return Position future de gauche
    Coord nextMoveLeft();

    /// @brief Grandir le serpent
    void grandi();

    /// @brief Changer des direction
    /// @param d La direction
    void changeDirection(char d){this->m_direction = d;}

    /// @brief Changer la velocité
    void changeVelocity(){this->m_velocity += 1;}

    /// @brief Vérifier les position intédites
    /// @param game Voir comment arreter le jeux
    void checkPositionInterdit(int *game);

    

private:
    /// @brief La position du serpent
    Coord posSnake;

    /// @brief La structure du serpent
    std::vector< Cell> the_snake;

    /// @brief Le plateau contenant le serpent
    Board *m_frameParent;

    /// @brief La direction des mouvements
    char m_direction;

    /// @brief La vitesse
    int m_velocity;


    /// @brief Créer la t\^ete du serpent
    void createHead();
};

#endif //