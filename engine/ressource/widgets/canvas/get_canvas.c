/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** get_canvas.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/core.h"
#include "engine/window.h"

static gbool_t is_equal(search_t search, canvas_t *canvas, void *prop)
{
    v2i_t pos;

    if (canvas == NULL)
        return FALSE;
    if (search == NAME && !my_strcmp(canvas->name, prop))
        return TRUE;
    if (search == POS_MV) {
        pos = *(v2i_t *) prop;
        RETURN_IF(pos.x >= canvas->pos.x &&
            pos.x <= canvas->pos.x + canvas->size.x &&
            pos.y >= canvas->pos.y &&
            pos.y <= canvas->pos.y + canvas->size.y, TRUE);
    }
    if (search == POS) {
        pos = *(v2i_t *) prop;
        RETURN_IF(canvas->pos.x == pos.x && canvas->pos.y == pos.y, TRUE);
    }
    return FALSE;
}

static canvas_t *search_canvas(search_t srch, char *prop, list_widgets_t *list)
{
    list_widgets_t *current = list;
    canvas_t *canvas;
    canvas_t *found;

    while (current != NULL) {
        canvas = current->content;
        if (current->type == CANVAS) {
            RETURN_IF(canvas == NULL, NULL);
            found = search_canvas(srch, prop, canvas->widgets);
            RETURN_IF(found != NULL, found);
        }
        if (is_equal(srch, canvas, prop))
            return canvas;
        current = current->next;
    }
    return NULL;
}

static canvas_t *getcanvas_prop(void *prop, search_t srch, gbool_t use_preload)
{
    canvas_t **actual = get_mapinfo()->canvas;
    canvas_t *current;

    for (int i = 0; i <= 1; i++) {
        for (int x = 0; actual != NULL && actual[x]; x++) {
            RETURN_IF(is_equal(srch, actual[x], prop), actual[x]);
            current = search_canvas(NAME, prop, actual[x]->widgets);
            RETURN_IF(current != NULL, current);
        }
        if (use_preload)
            actual = get_mapinfo()->preloaded;
    }
    return NULL;
}

canvas_t *getcanvas_name(char *name)
{
    return getcanvas_prop(name, NAME, TRUE);
}

v2i_t getcanvas_pos_by_name(char *name)
{
    canvas_t *canvas = getcanvas_name(name);

    if (canvas == NULL)
        return (v2i_t) {-1, -1};
    return canvas->pos;
}

v2f_t getcanvas_size_by_name(char *name)
{
    canvas_t *canvas = getcanvas_name(name);

    if (canvas == NULL)
        return (v2f_t) {-1.0, -1.0};
    return canvas->size;
}

list_widgets_t *getcanvas_widget_by_name(char *name)
{
    canvas_t *canvas = getcanvas_name(name);

    if (canvas == NULL)
        return NULL;
    return canvas->widgets;
}

canvas_t *getcanvas_atposition(int x, int y)
{
    canvas_t *actual = get_mapinfo()->actual;
    v2i_t pos = {x, y};

    if (is_equal(POS_MV, actual, (void *) &pos))
        return actual;
    return getcanvas_prop((void *) &pos, POS_MV, FALSE);
}
