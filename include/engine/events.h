/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** events.h
*/

#include "core.h"
#ifndef EVENTS_H
    #define EVENTS_H

typedef void (*events_fct)();
typedef struct events_s events_t;

struct events_s {
    sfEvent event;
    events_fct event_handler[24];
};

void init_events(void);
void register_event(sfEventType evt_type, events_fct elemtn);
void event_manager(void);

#endif
