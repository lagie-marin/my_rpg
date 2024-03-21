/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** types.h
*/
#include "core.h"
#ifndef TYPES_H
    #define TYPES_H
typedef sfVector2f v2f;
typedef sfVector2i v2i;
typedef sfVector2u v2u;
typedef sfUint8 ui8;
typedef sfUint16 ui16;
typedef sfUint32 ui32;
typedef sfUint64 ui64;
typedef short int si;                   // -32 768 to 32 767
typedef unsigned short int usi;         // 0 to 65 535
typedef unsigned int ui;                // 0 to 4 294 967 295
typedef long int li;                    // -2 147 483 648 to 2 147 483 647
typedef long long int lli;              // -(2^63) to (2^63)-1
typedef unsigned long long int ulli;    // 0 to 18 446 744 073 709 551 615
typedef signed char sc;                 // -128 to 127
typedef unsigned char uc;               // 0 to 255
typedef unsigned char *ustr;
typedef enum gbool_e gbool;
typedef enum element_type_e element_type;

enum gbool_e {
    FALSE,
    TRUE
};

enum element_type_e {
    WIDGET,
    PARTICULE,
    BACKGROUND,
    SPRITE
};

#endif
