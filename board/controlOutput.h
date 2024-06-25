#ifndef FILE_CONTROL_OUTPUT_H
#define FILE_CONTROL_OUTPUT_H

#pragma once

#include <cstdio>
#include <iostream>

/// @brief definiton des couleur de la console normal
#define TC_NRM "\x1B[0m"

/// @brief la couleur Rouge
#define TC_RED "\x1B[1;31m"

/// @brief La couleur verte
#define TC_GRN "\x1B[1;32m"

/// @brief La couleur jaune
#define TC_YEL "\x1B[1;33m"

/// @brief Le bleu
#define TC_BLU "\x1B[1;34m"

/// @brief Le magenta
#define TC_MAG "\x1B[1;34m"

/// @brief Le cyan
#define TC_CYN "\x1B[1;36m"

/// @brief Le blanc
#define TC_WTH "\x1B[1;37m"

/// @brief La couleur foncé
#define TC_B_NRM "\x1B[0m"

/// @brief Le rouge foncé
#define TC_B_RED "\x1B[0;31m"

/// @brief Le vert foncé
#define TC_B_GRN "\x1B[0;32m"

/// @brief Le jaune foncé
#define TC_B_YEL "\x1B[0;33m"

/// @brief Le bleu foncé
#define TC_B_BLU "\x1B[0;34m"

/// @brief Le magenta foncé
#define TC_B_MAG "\x1B[0;34m"

/// @brief Le cyan foncé
#define TC_B_CYN "\x1B[0;36m"

/// @brief Le blanc foncé
#define TC_B_WTH "\x1B[0;37m"


/// @brief Le normal de fond
#define TC_BG_NRM "\x1B[40m"

/// @brief Le rouge de fond
#define TC_BG_RED "\x1B[41m"

/// @brief Le vert de fond
#define TC_BG_GRN "\x1B[42m"

/// @brief Le jaune de fond
#define TC_BG_YEL "\x1B[43m"

/// @brief Le bleu de fond
#define TC_BG_BLU "\x1B[44m"

/// @brief Le Magenta de fond
#define TC_BG_MAG "\x1B[45m"

/// @brief Le Cyan de fond
#define TC_BG_CYN "\x1B[46m"

/// @brief Le blanc de fond
#define TC_BG_WTH "\x1B[47m"

/// @brief netoyage
#define tc_clear_screen() std::cout<<"\x1B[2J"

/// @brief déplacer le curseur
#define tc_move_cursor(X,Y) std::cout<<"\033["<<Y<<";"<<X<<"H"

#endif // FILE_CONTROL_OUTPUT_H