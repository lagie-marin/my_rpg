/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** event_manager.c
*/

#include "engine/window.h"
void event_manager(void)
{
    window_infos_t *windows = Game_engine->windows;
    events_fct_t *event_handler = get_events();
    sfEvent event;

    while (sfRenderWindow_pollEvent(windows->window, &event))
        event_handler[event.type](event);
}
