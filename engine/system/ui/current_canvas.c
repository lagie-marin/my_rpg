/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** current_canvas.c
*/
#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/window.h"

void setcurrent_canvas(int x, int y)
{
    canvas_t **canvas = get_mapinfo()->canvas;

    for (int i = 0; canvas[i]; i++)
        if (atposition_contain_canvas(x, y, canvas[i])) {
            get_mapinfo()->actual = canvas[i];
            return;
        }
}

canvas_t *getcurrent_canvas(void)
{
    return get_mapinfo()->actual;
}
