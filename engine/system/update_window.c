/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** update_window.c
*/
#include "engine/window.h"

static void render_element(canvas_t *canvas)
{
    list_widgets_t *current;

    if (canvas == NULL)
        return;
    current = canvas->widgets;
    while (current != NULL && canvas->visible == TRUE) {
        if (current->type == CANVAS)
            render_element(current->content);
        if (current->type == BUTTON)
            draw_button(current->content);
        current = current->next;
    }
}

void update_window(void)
{
    canvas_t **canvas = get_mapinfo()->canvas;

    for (int i = 0; canvas[i]; i++)
        render_element(canvas[i]);
}
