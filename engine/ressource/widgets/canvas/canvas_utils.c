/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** canvas_utils.c
*/
#include "engine/widgets/widgets.h"

void load_canvas(canvas_t *canvas)
{
    list_widgets_t *widgets;

    if (canvas == NULL || canvas->visible == TRUE)
        return;
    widgets = canvas->widgets;
    canvas->visible = TRUE;
    while (widgets != NULL) {
        load[widgets->type](widgets->content);
        widgets = widgets->next;
    }
}

void unload_canvas(canvas_t *canvas)
{
    list_widgets_t *widgets;

    if (canvas == NULL)
        return;
    widgets = canvas->widgets;
    canvas->visible = FALSE;
    while (widgets != NULL) {
        unload[widgets->type](widgets->content);
        widgets = widgets->next;
    }
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
