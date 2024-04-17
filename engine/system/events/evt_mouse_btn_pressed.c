/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** evt_mouse_btn_pressed.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void interact_widgets(list_widgets_t *widgets, sfEvent event)
{
    void *content;

    if (widgets == NULL)
        return;
    content = widgets->content;
    if (widgets->type == BUTTON)
        ((button_t *)content)->fpressed(content, event.mouseButton);
}

void evt_mouse_btn_pressed(sfEvent event)
{
    int x = event.mouseButton.x;
    int y = event.mouseButton.y;
    list_widgets_t *widgets = at_coordinate(x, y);

    interact_widgets(widgets, event);
    (void)event;
    return;
}
