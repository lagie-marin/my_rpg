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
    events_t events = Game_engine->events;
    sfEventType type;
    sfEvent event;

    while (sfRenderWindow_pollEvent(windows->window, &events.event)) {
        event = events.event;
        type = event.type;
        if (IS_CLOSED(type))
            events.event_handler[type]();
        if (IS_MOUSE_BTN(type))
            events.event_handler[type](event.mouseButton);
        if (IS_MOUSE_MV(type)) {
            setcurrent_canvas(event.mouseMove.x, event.mouseMove.y);
            events.event_handler[type](event.mouseMove);
        }
    }
}
