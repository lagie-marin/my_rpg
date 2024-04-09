/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** types.h
*/
#include "core.h"
#ifndef TYPES_H
    #define TYPES_H
typedef sfVector2f v2f_t;
typedef sfVector2i v2i_t;
typedef sfVector2u v2u_t;
typedef sfUint8 ui8_t;
typedef sfUint16 ui16_t;
typedef sfUint32 ui32_t;
typedef sfUint64 ui64_t;
typedef short int si_t;                   // -32 768 to 32 767
typedef unsigned short int usi_t;         // 0 to 65 535
typedef unsigned int ui_t;                // 0 to 4 294 967 295
typedef long int li_t;                    // -2 147 483 648 to 2 147 483 647
typedef long long int lli_t;              // -(2^63) to (2^63)-1
typedef unsigned long long int ulli_t;    // 0 to 18 446 744 073 709 551 615
typedef signed char sc_t;                 // -128 to 127
typedef unsigned char uc_t;               // 0 to 255
typedef unsigned char *ustr_t;
typedef enum gbool_e gbool_t;
typedef enum element_type_e element_type_t;

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
