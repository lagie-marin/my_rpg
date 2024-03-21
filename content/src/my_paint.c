/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** my_paint.c
*/
#include "engine.h"

status construct(void)
{
    status stat = load("paint");
    canvas_t *canvas;

    my_printf("stat: %i\n", stat);
    RETURN_IF(stat == FAIL, FAIL);
    canvas = getcanvas_name("antoine");
    RETURN_IF(canvas == NULL, SUCCESS);
    my_printf("name: %s\n", canvas->name);
    return SUCCESS;
}

void paint(sfRenderWindow *window, sfRectangleShape *brush)
{
    sfVector2i mouse_pos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfRectangleShape_setPosition(brush, (v2f){mouse_pos.x, mouse_pos.y});
        sfRenderWindow_drawRectangleShape(window, brush, NULL);
    }
}

void evt_tickrate(void)
{
    return;
}
