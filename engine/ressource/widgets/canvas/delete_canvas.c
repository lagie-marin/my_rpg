/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** delete_canvas.c
*/
#include "engine/widgets/widgets.h"

void delete_canvas(canvas_t *canvas)
{
    if (canvas == NULL)
        return;
    FREE(canvas->name);
    delete_widget(canvas->widgets);
    FREE(canvas);
}

void delete_all_canvas(canvas_t **canvas)
{
    for (int i = 0; canvas[i]; i++)
        delete_canvas(canvas[i]);
    FREE(canvas);
}
