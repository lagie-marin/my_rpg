/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** init_events.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void default_evt_closed(void)
{
    sfRenderWindow_close(Game_engine->windows->window);
}

static void none_evt(void)
{
    return;
}

void init_events(void)
{
    my_printf("Init events\n");
    Game_engine->events.event_handler[sfEvtClosed] = &default_evt_closed;
    for (int i = 1; i <= 22; i++)
        Game_engine->events.event_handler[i] = &none_evt;
}
