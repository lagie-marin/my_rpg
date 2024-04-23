/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** color.h
*/
#include "core.h"
#include "widgets/widgets.h"
#ifndef COLOR_H
    #define COLOR_H
    #define GREY color(244, 244, 244, 255)
    #define BEIGE color(234, 220, 166, 255)
    #define GOLD color(226, 194, 117, 255)
    #define ORANGE color(195, 106, 45, 255)

void settexture(sfRectangleShape *btn_shape, texture_t *texture);
#endif
