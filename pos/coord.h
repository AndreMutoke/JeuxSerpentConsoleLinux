#ifndef COORD_CELL_H
#define COORD_CELL_H

#pragma once

#include <iostream>

/// @brief Coord est la structure gérant le positionnement
struct Coord
{
    int x;
    int y;
};
/// @brief Redéfinition de struct Coord en Coord
typedef struct Coord Coord;

/// @brief Initialisation des coordonnées
/// @param src positions source
void initCoord(Coord *src);

/// @brief Copier les positions
/// @param src La position source
/// @param dest La position de destination
void CopyCoord(Coord *src, Coord *dest);

/// @brief Creer une position
/// @param x Le paramètre en x
/// @param y Le paramètre en y
/// @param coord1 La coordonnée en question
void CreateCoord(int x, int y, Coord *coord1);

/// @brief Permuter les valeurs des coordonnées
/// @param coord1 La première coordonnée
/// @param coord2 La seconde coordonnée
void permutCoord(Coord *coord1, Coord *coord2);

/// @brief Comparer deux coordonnées
/// @param coord1 La prémière Coordonnée
/// @param coord2 La seconde coordonnée
/// @return INT selon que c'est similaire ou pas
int compareCoords(Coord *coord1, Coord *coord2);

#endif // COORD_CELL_H