/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** game_loop.c
*/
#include "engine/color.h"
#include "engine/core.h"
#include "engine/window.h"

void game_loop(void)
{
    window_infos_t *windows = Game_engine->windows;

    sfRenderWindow_setFramerateLimit(windows->window, windows->fps);
    while (sfRenderWindow_isOpen(windows->window)) {
        sfRenderWindow_clear(windows->window, sfWhite);
        event_manager();
        update_window();
        event_tick();
        sfRenderWindow_display(windows->window);
    }
}
