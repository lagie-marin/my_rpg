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
    get_mapinfo()->actual = getcanvas_atposition(x, y);
}

canvas_t *getcurrent_canvas(void)
{
    return get_mapinfo()->actual;
}
