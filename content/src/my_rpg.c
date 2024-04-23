/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** my_rpg.c
*/

#include "engine.h"

status_t construct(void)
{
    status_t stat = load_map("menu");
    canvas_t *canvas;

    RETURN_IF(stat == FAIL, FAIL);
    canvas = getcanvas_name("header");
    RETURN_IF(canvas == NULL, SUCCESS);
    return SUCCESS;
}

void event_tick(void)
{
    static int write = 0;

    if (!write)
        write = 1;
    return;
}
