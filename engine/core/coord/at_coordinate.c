/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** at_coordinate.c
*/
#include "engine/widgets/widgets.h"
#include "engine/window.h"

static widgets_t *widgets(void)
{
    static widgets_t widgets_handler[2];
    static int is_init = FALSE;

    if (is_init == TRUE)
        return widgets_handler;
    widgets_handler[CANVAS] = &atposition_contain_canvas;
    widgets_handler[BUTTON] = &atposition_contain_button;
    is_init = TRUE;
    return widgets_handler;
}

list_widgets_t *at_coordinate(int x, int y)
{
    canvas_t *canvas = get_mapinfo()->actual;
    widgets_t *widgets_handler = widgets();
    list_widgets_t *current = NULL;

    if (canvas == NULL)
        return NULL;
    current = canvas->widgets;
    while (current != NULL) {
        if (widgets_handler[current->type](x, y, current->content) == TRUE)
            return current;
        current = current->next;
    }
    return NULL;
}
