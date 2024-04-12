/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** setbtn_shape.c
*/
#include "engine/core.h"
#include "engine/widgets/widgets.h"

static void applybutton_texture(button_t *button, texture_t *texture)
{
    sfRectangleShape *btn_shape = button->btn_shape;

    setbtn_shape_pos(button, button->pos);
    setbtn_shape_size(button, button->size);
    setbtn_shape_scale(button, button->scale);
    sfRectangleShape_setFillColor(btn_shape, texture->tint);
    sfRectangleShape_setOutlineThickness(btn_shape, button->thickness);
    sfRectangleShape_setOutlineColor(btn_shape, texture->border);
}

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

void setbtn_shape_by_name_texture(button_t *button, char *name_texture)
{
    texture_t *texture = gettexture_by_name(name_texture);

    applybutton_texture(button, texture);
}

void setbtn_shape_by_texture(button_t *button, texture_t *texture)
{
    applybutton_texture(button, texture);
}
