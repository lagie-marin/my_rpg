/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_mouse_moved.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void setcurrent_canvas(int x, int y)
{
    canvas_t **canvas = get_mapinfo()->canvas;

    for (int i = 0; canvas[i]; i++)
        if (atposition_contain_canvas(x, y, canvas[i])) {
            get_mapinfo()->actual = canvas[i];
            return;
        }
}

void evt_mouse_moved(sfEvent event)
{
    int x = event.mouseMove.x;
    int y = event.mouseMove.y;
    list_widgets_t *widgets = at_coordinate(x, y);

    interact_widget(widgets, event, EVT_MOVE);
    setcurrent_canvas(x, y);
    return;
}
