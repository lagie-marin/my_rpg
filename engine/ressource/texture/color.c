/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** color.c
*/

#include "engine/core.h"
#include "engine/widgets/widgets.h"

sfColor color(int r, int g, int b, int a)
{
    return (sfColor) {r, g, b, a};
}

void settexture(sfRectangleShape *btn_shape, texture_t *texture)
{
    sfRectangleShape_setFillColor(btn_shape, texture->tint);
    if (texture->texture != NULL)
        sfRectangleShape_setTexture(btn_shape, texture->texture, sfFalse);
}
