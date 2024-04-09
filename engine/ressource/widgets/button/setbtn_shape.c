/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** setbtn_shape.c
*/
#include "engine/core.h"
#include "engine/widgets/widgets.h"

void setbtn_shape_pos(button_t *button, v2f_t pos)
{
    sfRectangleShape_setPosition(button->btn_shape, pos);
}

void setbtn_shape_size(button_t *button, v2f_t size)
{
    sfRectangleShape_setSize(button->btn_shape, size);
}

void setbtn_shape_scale(button_t *button, v2f_t scale)
{
    sfRectangleShape_setScale(button->btn_shape, scale);
}

int setbtn_shape(button_t *button, char *name_texture)
{
    sfRectangleShape *btn_shape = button->btn_shape;
    texture_t *texture = gettexture_by_name(name_texture);

    sfRectangleShape_setFillColor(btn_shape, texture->tint);
    sfRectangleShape_setOutlineThickness(btn_shape, button->thickness);
    sfRectangleShape_setOutlineColor(btn_shape, texture->border);
    return 0;
}
