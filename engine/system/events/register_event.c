/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** register_event.c
*/
#include "engine/events.h"

void register_event(sfEventType evt_type, events_fct fct)
{
    events_t evt;

    evt.event_handler[evt_type] = fct;
    evt.event_handler[evt_type]();
}
