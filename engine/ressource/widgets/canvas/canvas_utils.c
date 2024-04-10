/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** canvas_utils.c
*/
#include "engine/widgets/widgets.h"

void load_canvas(canvas_t *canvas)
{
    list_widgets_t **widgets;

    if (canvas == NULL || canvas->visible == TRUE)
        return;
    widgets = canvas->widgets;
    canvas->visible = TRUE;
    for (int i = 0; widgets[i]; i++)
        load[widgets[i]->type](widgets[i]->content);
}

void unload_canvas(canvas_t *canvas)
{
    list_widgets_t **widgets;

    if (canvas == NULL)
        return;
    widgets = canvas->widgets;
    canvas->visible = FALSE;
    for (int i = 0; widgets[i]; i++)
        unload[widgets[i]->type](widgets[i]->content);
}

void delete_canvas(canvas_t *canvas)
{
    if (canvas == NULL)
        return;
    FREE(canvas->name);
    delete_widget(canvas->widgets);
    FREE(canvas);
}

void delete_all_canvas(canvas_t **canvas)
{
    for (int i = 0; canvas[i]; i++)
        delete_canvas(canvas[i]);
    FREE(canvas);
}
