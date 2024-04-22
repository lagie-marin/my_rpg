/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** button_utils.c
*/
#include "engine/window.h"
#include "engine/widgets/widgets.h"

void load_button(button_t *button)
{
    if (button->is_disabled == TRUE)
        setbtn_shape_by_name_texture(button, button->disabled->name);
    if (button->state == NORMAL)
        setbtn_shape_by_texture(button, button->normal);
    if (button->state == HOVERED)
        setbtn_shape_by_texture(button, button->hovered);
    if (button->state == PRESSED)
        setbtn_shape_by_texture(button, button->pressed);
}

void draw_button(button_t *button)
{
    sfRenderWindow *win = get_engine()->windows->window;

    sfRenderWindow_drawRectangleShape(win, button->btn_shape, NULL);
}

void unload_button(button_t *button)
{
    sfRectangleShape_destroy(button->btn_shape);
    button->btn_shape = NULL;
}

void delete_button(button_t *button)
{
    if (button == NULL)
        return;
    FREE(button->name);
    sfRectangleShape_destroy(button->btn_shape);
    FREE(button);
}
