/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** parse_canvas.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/core.h"
#include "engine/window.h"

static void add_canvas(canvas_t *new_canvas)
{
    canvas_t **canvas = get_mapinfo()->canvas;
    canvas_t **new = malloc((len_step(canvas) + 2) * sizeof(canvas_t));
    int i = 0;

    for (; canvas[i]; i++)
        new[i] = canvas[i];
    FREE(canvas);
    new[i] = new_canvas;
    new[i + 1] = NULL;
    get_mapinfo()->canvas = new;
}

static void add_canvas_on_map(canvas_t *new_canvas, canvas_t **step)
{
    int len = len_step(step);

    if (len == 0)
        add_canvas(new_canvas);
    else
        add_widget(&step[0]->widgets, new_canvas, CANVAS);
}

sload_t gmap_parse_canvas(char *line, canvas_t ***step, sload_t tl)
{
    array_t elmt = my_strtok(line, ';');
    canvas_t *new = create_canvas(elmt[1]);

    if (getcanvas_name(elmt[1])) {
        put_error("Le nom du canvas: ");
        put_error(elmt[1]);
        put_error(" existe déjà\n");
        FREE(elmt[0]);
        free_strnarray(elmt, 2);
        delete_canvas(new);
        return ERROR;
    }
    setcanvas_pos(new, (v2i_t) {my_atoi(elmt[2]), my_atoi(elmt[3])});
    setcanvas_size(new, (v2f_t) {my_strtof(elmt[4]), my_strtof(elmt[5])});
    setcanvas_widget(new, NULL);
    FREE(elmt[0]);
    free_strnarray(elmt, 2);
    add_canvas_on_map(new, *step);
    *step = add_step(*step, new);
    return tl;
}
