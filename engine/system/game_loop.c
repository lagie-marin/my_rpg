/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** game_loop.c
*/
#include "engine/window.h"
#include "my_paint/my_paint.h"

void game_loop(void)
{
    window_infos_t *windows = Game_engine->windows;
    sfRectangleShape *brush = sfRectangleShape_create();

    sfRectangleShape_setSize(brush, (v2f){2, 2});
    sfRectangleShape_setFillColor(brush, sfRed);
    sfRenderWindow_setFramerateLimit(windows->window, windows->fps);
    sfRenderWindow_clear(windows->window, sfWhite);
    while (sfRenderWindow_isOpen(windows->window)) {
        event_manager();
        evt_tickrate();
        paint(windows->window, brush);
        sfRenderWindow_display(windows->window);
    }
    window_destroy();
}
