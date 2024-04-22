/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event_button.c
*/
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/color.h"

void default_hovered(button_t *button, sfMouseMoveEvent mouse)
{
    sfColor tint = button->hovered->tint;

    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = HOVERED;
    sfRectangleShape_setFillColor(button->btn_shape, tint);
}

void default_unhovered(button_t *button, sfMouseMoveEvent mouse)
{
    texture_t *texture = button->normal;
    sfColor tint = texture->tint;

    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = NORMAL;
    if (!texture->texture)
        sfRectangleShape_setFillColor(button->btn_shape, tint);
    else
        sfRectangleShape_setTexture(button->btn_shape, texture->texture, sfFalse);
}

void default_pressed(button_t *button, sfMouseButtonEvent mouse)
{
    sfColor tint = button->pressed->tint;

    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = PRESSED;
    sfRectangleShape_setFillColor(button->btn_shape, tint);
}

void default_released(button_t *button, sfMouseButtonEvent mouse)
{
    sfColor tint = button->hovered->tint;

    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = HOVERED;
    sfRectangleShape_setFillColor(button->btn_shape, tint);
}
