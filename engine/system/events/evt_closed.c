/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_closed.c
*/
#include "engine/window.h"
#include "engine/events.h"

void evt_closed(sfEvent event)
{
    (void)event;
    sfRenderWindow_close(get_engine()->windows->window);
}
