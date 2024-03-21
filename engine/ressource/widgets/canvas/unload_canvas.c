/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** unload_canvas.c
*/
#include "../../../../include/engine/core.h"
#include "../../../../include/engine/widgets/widgets.h"

void unload_canvas(canvas_t *canvas)
{
    if (canvas == NULL)
        return;
    FREE(canvas->name);
    unload_widget(canvas->widgets);
    FREE(canvas);
}

void unload_all_canvas(canvas_t **canvas)
{
    for (int i = 0; canvas[i]; i++)
        unload_canvas(canvas[i]);
    FREE(canvas);
}
