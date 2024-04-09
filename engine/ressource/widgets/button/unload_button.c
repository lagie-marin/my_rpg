/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** unload_button.c
*/
#include "engine/widgets/widgets.h"

void unload_button(button_t *button)
{
    sfRectangleShape_destroy(button->btn_shape);
    button->btn_shape = NULL;
}
