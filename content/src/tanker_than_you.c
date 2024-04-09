/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** tanker_than_you.c
*/

#include "engine.h"

status_t construct(void)
{
    status_t stat = load("paint");
    canvas_t *canvas;

    my_printf("stat: %i\n", stat);
    RETURN_IF(stat == FAIL, FAIL);
    canvas = getcanvas_name("header");
    RETURN_IF(canvas == NULL, SUCCESS);
    my_printf("name: %s\n", canvas->name);
    return SUCCESS;
}

void paint(sfRenderWindow *window, sfRectangleShape *brush)
{
    sfVector2i mouse_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfRectangleShape_setPosition(brush, (v2f_t){mouse_pos.x, mouse_pos.y});
        sfRenderWindow_drawRectangleShape(window, brush, NULL);
    }
}

void evt_tickrate(void)
{
    return;
}
