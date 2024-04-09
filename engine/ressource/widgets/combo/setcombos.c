/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** setcombos.c
*/
#include "engine/types.h"
#include "engine/widgets/widgets.h"

void setcombos_name(combos_t *combos, char *name)
{
    combos->name = name;
}

void setcombos_pos(combos_t *combos, v2f_t pos)
{
    combos->pos = pos;
}

void setcombos_size(combos_t *combos, v2f_t size)
{
    combos->size = size;
}

void setcombos_options(combos_t *combos, array_t options, int selected_opt)
{
    combos->option = options;
    combos->selected_opt = selected_opt;
}

void setcombos_display_arrow(combos_t *combos, gbool_t display)
{
    combos->display_arrow = display;
}
