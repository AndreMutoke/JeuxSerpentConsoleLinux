#ifndef COLOR_CELL_H
#define COLOR_CELL_H

#pragma once

#include <iostream>

/// @brief Structre de la couleur
struct color
{
    /* data */
    int r;
    int v;
    int b;
};
/// @brief Rédefinition de struct color en color
typedef struct  color color;

/// @brief Initialiser la couleur
/// @param src La couleur
void initColor(color *src); 

/// @brief Copier la couleur
/// @param clrsrc La couleur source
/// @param clrdest La couleur de déstination
void ColorCopy(color *clrsrc, color *clrdest);

/// @brief Créer une couleur
/// @param r Le rouge
/// @param v Le vert 
/// @param b Le bleu
/// @param clr La couleur
void createColor(int r, int v, int b, color *clr);

/// @brief Pérmutter les valeurs de couleur
/// @param clr1 La couleur 1
/// @param clr2 La couleur 2
void permutColor(color *clr1, color *clr2);

#endif // COLOR_CELL_H

