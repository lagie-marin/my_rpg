/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** init_events.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void none_evt(sfEvent event)
{
    return;
}

events_fct_t *get_events(void)
{
    static events_fct_t event_handler[24];
    static gbool_t is_init = FALSE;

    if (is_init == TRUE)
        return event_handler;
    my_printf("Init events\n");
    for (int i = 0; i <= 22; i++)
        event_handler[i] = &none_evt;
    event_handler[sfEvtClosed] = &evt_closed;
    event_handler[sfEvtMouseButtonPressed] = &evt_mouse_btn_pressed;
    event_handler[sfEvtMouseButtonReleased] = &evt_mouse_btn_released;
    event_handler[sfEvtMouseMoved] = &evt_mouse_moved;
    is_init = TRUE;
    return event_handler;
}
