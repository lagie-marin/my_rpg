/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_mouse_moved.c
*/
#include "engine/window.h"
#include "engine/events.h"

void evt_mouse_moved(sfEvent event)
{
    setcurrent_canvas(event.mouseMove.x, event.mouseMove.y);
    return;
}
