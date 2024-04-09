/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** event_button.c
*/
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/color.h"

void default_hovered(button_t *button, sfMouseMoveEvent *mouse)
{
    if (mouse == NULL)
        return;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, BEIGE);
}

void default_pressed(button_t *button, sfMouseButtonEvent *mouse)
{
    if (mouse == NULL)
        return;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, GOLD);
}

void default_released(button_t *button, sfMouseButtonEvent *mouse)
{
    if (mouse == NULL)
        return;
    if (button->is_disabled == FALSE)
        sfRectangleShape_setFillColor(button->btn_shape, GREY);
}
