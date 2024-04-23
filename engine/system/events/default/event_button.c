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
    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = HOVERED;
    my_printf("Texture exist: %i in hover\n", button->hovered->texture);
    settexture(button->btn_shape, button->hovered);
}

void default_unhovered(button_t *button, sfMouseMoveEvent mouse)
{
    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = NORMAL;
    my_printf("Texture exist: %i in unhover\n", button->normal->texture);
    settexture(button->btn_shape, button->normal);
}

void default_pressed(button_t *button, sfMouseButtonEvent mouse)
{
    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = PRESSED;
    my_printf("Texture exist: %i in pressed\n", button->pressed->texture);
    settexture(button->btn_shape, button->pressed);
}

void default_released(button_t *button, sfMouseButtonEvent mouse)
{
    (void)mouse;
    if (button->is_disabled == TRUE)
        return;
    button->state = HOVERED;
    my_printf("Texture exist: %i in released\n", button->hovered->texture);
    settexture(button->btn_shape, button->hovered);
}
