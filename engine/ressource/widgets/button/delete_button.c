/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** delete_button.c
*/
#include "engine/widgets/widgets.h"

void delete_button(button_t *button)
{
    if (button == NULL)
        return;
    FREE(button->name);
    sfRectangleShape_destroy(button->btn_shape);
    FREE(button);
}
