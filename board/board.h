#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <vector>

#include "../color/color.h"
#include "../pos/coord.h"

/// @brief VARIABLE GLOBAL la largeur de l'ecran
#define MAX_BOARD_WIDTH 120 // By default

/// @brief VARIABLE GLOBAL la hauteur de l'ecran
#define MAX_BOARD_HEIGHT 160 // By default


/// @brief Valeur d'un espace vide de fin de chaine
#define VACCUM '\0'

/// @brief Valeur de la bordure de l'ecran
#define BORDURE '#'

/// @brief Valeur de la tete du serpent
#define HEAD '@'


/// @brief La classe Board gere la plateforme du jeux
class Board
{
public:
/***
 * CONSTRUCTEURS
*/

    /// @brief Board est le premier constructeur de la classe
    /// @param w la largeur du plateau
    /// @param h la hauteur du plateau
    /// @param pos la position du plateau en COORD
    Board(int w, int h, Coord *pos);

    /// @brief Le second constructeur du plateau, ici par defaut le plateau est mis a la position (0, 0)
    /// @param w les parametres de la largeur du plateau
    /// @param h les parametre de la hauteur du plateau 
    Board(int w = MAX_BOARD_WIDTH, int h = MAX_BOARD_HEIGHT);

/***
 * METHODES PUBLIQUES
*/
    /// @brief Affichage du plateau
    void Show(void);

    /// @brief recupere la position du plateau
    /// @return Coord la position du plateau
    Coord getPosBoard(){return this->posBoard;}

    /// @brief recupere la largeur du plateau
    /// @return INT la largeur
    int getWidthBoard(){return this->m_width;}

    /// @brief Recupère la hauteur du plateau
    /// @return INT la hauteur du plateau
    int getHeightBoard(){return this->m_height;}

    /// @brief Placer le plateau à une position
    /// @param coord1 La nouvelle position du plateau
    void setPosBoard(Coord *coord1){CopyCoord(coord1, &this->posBoard);}

    /// @brief Insérer une information de couleur du Pixel à une position du plateau
    /// @param coord1 La position sur laquelle on veut insérer
    /// @param clr1 La couleur à insérer
    void setPixelColor(Coord *coord1, color *clr1);

    /// @brief Insérer les caractéristique de l'élément à la position donnée.
    /// @param coord1 Les coordonnées de position
    /// @param elmnt La valeur de l'élément
    void setElement(Coord *coord1, char elmnt);

private:
    /// @brief La largeur de l'écran
    int m_width;// La largeur de la fenetre

    /// @brief La hauteur de l'écran
    int m_height; // La hauteur de la fenetre

    /// @brief La position du plateau
    Coord posBoard; // La position de la fenetre par rapport a l'ecran

    /// @brief Le vecteur contenant les information de couleur
    std::vector< std::vector<color> > pixelBoard;

    /// @brief Le vecteur contenant les informtion des élément 
    std::vector< std::vector<char> > element;

    /// @brief Centrer le plateau
    /// @param wScreen La largeur du plateau
    /// @param hScreen La hauteur du plateau
    /// @return COORD les coordonnés permettant de centrer le plateau
    Coord centerBoard(int wScreen, int hScreen);

    /// @brief Définit l'écran en placant chaque chose à sa place sur l'écran
    void defineBoard(void);

    /// @brief Initialise le vecteur du plateau
    void initMap(void);

    /// @brief Initialiser les elements du plateau 
    void initElements(void);

};

/// @brief Redéfinition de Board en Cell
typedef Board Cell;

#endif // BOARD_H