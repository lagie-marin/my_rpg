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
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, tint);
}

void default_unhovered(button_t *button, sfMouseMoveEvent mouse)
{
    sfColor tint = button->normal->tint;

    (void)mouse;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, tint);
}

void default_pressed(button_t *button, sfMouseButtonEvent mouse)
{
    sfColor tint = button->pressed->tint;

    (void)mouse;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, tint);
}

void default_released(button_t *button, sfMouseButtonEvent mouse)
{
    sfColor tint = button->hovered->tint;

    (void)mouse;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, tint);
}
