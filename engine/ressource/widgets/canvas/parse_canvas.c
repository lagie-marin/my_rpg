/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** canvas.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/window.h"

static void add_canvas(canvas_t *new_canvas, gbool preloaded)
{
    canvas_t **canvas = get_mapinfo()->canvas;
    canvas_t **new = malloc((len_step(canvas) + 2) * sizeof(canvas_t));
    int i = 0;

    for (; canvas[i]; i++)
        new[i] = canvas[i];
    FREE(canvas);
    new[i] = new_canvas;
    new[i + 1] = NULL;
    if (preloaded == FALSE)
        get_mapinfo()->canvas = new;
    else
        get_mapinfo()->preloaded = new;
}

static void add_canvas_on_map(canvas_t *new_canvas, canvas_t **step)
{
    int len = len_step(step);

    my_printf("ici\n");
    if (len == 0)
        add_canvas(new_canvas, FALSE);
    else
        add_widget(&step[0]->widgets, new_canvas, CANVAS);
}

sload gmap_parse_canvas(char *line, canvas_t ***step, sload tl)
{
    array element = my_strtok(line, ';');
    canvas_t *new = create_canvas(element[1]);

    if (getcanvas_name(element[1])) {
        put_error("Le nom du canvas: ");
        put_error(element[1]);
        put_error(" existe déjà\n");
        FREE(element[0]);
        free_strnarray(element, 2);
        unload_canvas(new);
        return ERROR;
    }
    setcanvas_pos(new, (v2i) {my_atoi(element[2]), my_atoi(element[3])});
    setcanvas_size(new, (v2f) {my_strtof(element[4]), my_strtof(element[5])});
    setcanvas_widget(new, NULL);
    FREE(element[0]);
    free_strnarray(element, 2);
    add_canvas_on_map(new, *step);
    *step = add_step(*step, new);
    return tl;
}
