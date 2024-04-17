/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_mouse_moved.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void interact_widgets(list_widgets_t *widgets, sfEvent event)
{
    static list_widgets_t *old_widget = NULL;
    events_fct_t *event_move_handler = get_events_move();

    if (old_widget != NULL && (widgets == NULL || old_widget != widgets))
        if (old_widget->type == BUTTON)
            event_move_handler[1](old_widget->content, event.mouseMove);
    if (widgets != NULL) {
        if (widgets->type == BUTTON)
            event_move_handler[0](widgets->content, event.mouseMove);
        old_widget = widgets;
    }
}

void evt_mouse_moved(sfEvent event)
{
    int x = event.mouseMove.x;
    int y = event.mouseMove.y;
    list_widgets_t *widgets = at_coordinate(x, y);

    interact_widgets(widgets, event);
    setcurrent_canvas(x, y);
    return;
}
