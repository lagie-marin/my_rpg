/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_mouse_btn_released.c
*/
#include "engine/window.h"
#include "engine/events.h"

void evt_mouse_btn_released(sfEvent event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    list_widgets_t *widgets = at_coordinate(x, y);

    interact_widget(widgets, event, EVT_RELEASED);
    return;
}
