/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** get_button.c
*/
#include "engine/widgets/widgets.h"
#include "engine/window.h"

gbool_t atposition_contain_button(int x, int y, button_t *button)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->btn_shape);

    if (sfFloatRect_contains(&rect, (float) x, (float) y))
        return TRUE;
    return FALSE;
}
