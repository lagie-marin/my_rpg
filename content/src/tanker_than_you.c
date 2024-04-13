/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tanker_than_you.c
*/

#include "engine.h"

status_t construct(void)
{
    status_t stat = load_map("menu");
    canvas_t *canvas;

    my_printf("stat: %i\n", stat);
    RETURN_IF(stat == FAIL, FAIL);
    canvas = getcanvas_name("header");
    RETURN_IF(canvas == NULL, SUCCESS);
    my_printf("name: %s\n", canvas->name);
    return SUCCESS;
}

void event_tick(void)
{
    return;
}
