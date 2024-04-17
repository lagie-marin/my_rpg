/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** manager.c
*/
#include "engine/widgets/widgets.h"

void *getcontent(list_widgets_t *widget)
{
    if (widget == NULL)
        return NULL;
    return widget->content;
}

load_t load(widgets_type_t type)
{
    static load_t load_handler[2];
    static gbool_t is_init = FALSE;

    if (is_init == TRUE)
        return load_handler[type];
    load_handler[CANVAS] = &load_canvas;
    load_handler[BUTTON] = &load_button;
    is_init = TRUE;
    return load_handler[type];
}

unload_t unload(widgets_type_t type)
{
    static unload_t unload_handler[2];
    static gbool_t is_init = FALSE;

    if (is_init == TRUE)
        return unload_handler[type];
    unload_handler[CANVAS] = &unload_canvas;
    unload_handler[BUTTON] = &unload_button;
    is_init = TRUE;
    return unload_handler[type];
}

delete_t delete(widgets_type_t type)
{
    static delete_t delete_handler[2];
    static gbool_t is_init = FALSE;

    if (is_init == TRUE)
        return delete_handler[type];
    delete_handler[CANVAS] = &delete_canvas;
    delete_handler[BUTTON] = &delete_button;
    is_init = TRUE;
    return delete_handler[type];
}
