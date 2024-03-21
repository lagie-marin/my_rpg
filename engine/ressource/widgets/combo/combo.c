/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** combo.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/window.h"

// static sload unload_combos(combos_t *combos)
// {
//     FREE(combos->name);
//     free_strarray(combos->option);
//     return ERROR;
// }

combos_t *create_combos(char *name)
{
    combos_t *new = malloc(sizeof(combos_t));

    new->name = name;
    new->pos = (v2f) {0, 0};
    new->size = (v2f) {20, 20};
    new->option = NULL;
    new->selected_opt = -1;
    new->display_arrow = TRUE;
    new->normal = create_texture("normal");
    new->hovered = create_texture("hovered");
    new->pressed = create_texture("pressed");
    new->disabled = create_texture("disabled");
    return new;
}

sload gmap_parse_combo(char *line, canvas_t **step, sload tl)
{
    // array element = my_strtok(&line[nb_leading_space(line) + 6], ';');
    // combos_t *new = create_combos(element[0]);
    // array options = my_strtok(&element[5][1], ',');
    // int i = str_arraylen(options);
    // int selected = 0;

    // options[i - 1][LEN(options[i - 1]) - 1] = '\0';
    // setcombos_pos(new, (v2f) {my_strtof(element[1]), my_strtof(element[2])});
    // setcombos_size(new, (v2f) {my_strtof(element[3]), my_strtof(element[4])});
    // if (my_strcmp(element[6], "none"))
    //     selected = -1;
    // else if (my_str_isnum(element[6]))
    //     selected = my_atoi(element[6]);
    // else
    //     return unload_combos(new);
    // // setcombos_options(new, options, )
    // free_strarray(element);
    my_printf("%s, %d, %i", line, step, tl);
    return tl;
}
