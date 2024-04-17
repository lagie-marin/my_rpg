/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** widget_interaction.c
*/
#include "engine/window.h"
#include "engine/events.h"

static void interact_pressed(list_widgets_t *widget, sfEvent event)
{
    void *content;

    if (widget == NULL)
        return;
    content = widget->content;
    if (widget->type == BUTTON)
        ((button_t *)content)->fpressed(content, event.mouseButton);
}

static void interact_released(list_widgets_t *widget, sfEvent event)
{
    if (widget != NULL)
        if (widget->type == BUTTON)
            default_unhovered(widget->content, event.mouseMove);
}

static void interact_move(list_widgets_t *widget, sfEvent event)
{
    static list_widgets_t *old_widget = NULL;
    void *content = getcontent(widget);

    if (old_widget != NULL && (widget == NULL || old_widget != widget))
        if (old_widget->type == BUTTON)
            default_unhovered(old_widget->content, event.mouseMove);
    if (widget != NULL) {
        if (widget->type == BUTTON)
            ((button_t *)content)->fhovered(content, event.mouseMove);
        old_widget = widget;
    }
}

void interact_widget(list_widgets_t *widget, sfEvent event, type_event_t type)
{
    if (type == EVT_PRESSED)
        interact_pressed(widget, event);
    else if (type == EVT_RELEASED)
        interact_released(widget, event);
    else
        interact_move(widget, event);
}