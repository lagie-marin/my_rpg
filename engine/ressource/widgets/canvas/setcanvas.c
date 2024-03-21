/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** setcanvas.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/ressource.h"
#include "engine/window.h"
#include "engine/core.h"

canvas_t *create_canvas(char *name)
{
    canvas_t *new = malloc(sizeof(canvas_t));

    new->name = name;
    new->pos = (v2i) {0, 0};
    new->size = (v2f) {20.0, 20.0};
    new->widgets = NULL;
    return new;
}

void setcanvas_name(canvas_t *canvas, char *name)
{
    canvas->name = name;
}

void setcanvas_pos(canvas_t *canvas, v2i pos)
{
    canvas->pos = pos;
}

void setcanvas_size(canvas_t *canvas, v2f size)
{
    canvas->size = size;
}

void setcanvas_widget(canvas_t *canvas, void *widget)
{
    add_widget(&canvas->widgets, widget, CANVAS);
}
