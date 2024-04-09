/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create_canvas.c
*/
#include "engine/widgets/widgets.h"

canvas_t *create_canvas(char *name)
{
    canvas_t *canvas = malloc(sizeof(canvas_t));

    canvas->name = name;
    canvas->pos = (v2i_t) {0, 0};
    canvas->size = (v2f_t) {20.0, 20.0};
    canvas->widgets = NULL;
    canvas->visible = TRUE;
    return canvas;
}
