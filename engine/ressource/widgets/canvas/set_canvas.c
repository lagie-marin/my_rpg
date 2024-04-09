/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** set_canvas.c
*/
#include "engine/widgets/widgets.h"

void setcanvas_name(canvas_t *canvas, char *name)
{
    canvas->name = name;
}

void setcanvas_pos(canvas_t *canvas, v2i_t pos)
{
    canvas->pos = pos;
}

void setcanvas_size(canvas_t *canvas, v2f_t size)
{
    canvas->size = size;
}

void setcanvas_widget(canvas_t *canvas, void *widget)
{
    add_widget(&canvas->widgets, widget, CANVAS);
}
