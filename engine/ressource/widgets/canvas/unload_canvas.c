/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** unload_canvas.c
*/
#include "engine/core.h"
#include "engine/widgets/widgets.h"

void unload_canvas(canvas_t *canvas)
{
    list_widgets_t **widgets;

    if (canvas == NULL)
        return;
    widgets = canvas->widgets;
    canvas->visible = FALSE;
    for (int i = 0; widgets[i]; i++) {
        unload[widgets[i]->type](widgets[i]);
    }
}
