/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** parse_button.c
*/
#include "engine/widgets/widgets.h"

static gbool_t str_to_bool(char *boolean)
{
    if (!my_strcmp("true", boolean))
        return TRUE;
    return FALSE;
}

sload_t gmap_parse_button(char *line, canvas_t **step, sload_t tl)
{
    array_t elmt = my_strtok(&line[nb_leading_space(line) + 6], ';');
    button_t *btn = create_button(elmt[0]);

    btn->pos = (v2f_t) {my_strtof(elmt[1]), my_strtof(elmt[2])};
    btn->size = (v2f_t) {my_strtof(elmt[3]), my_strtof(elmt[4])};
    btn->scale = (v2f_t) {my_strtof(elmt[5]), my_strtof(elmt[6])};
    setbtn_shape_pos(btn, btn->pos);
    setbtn_shape_size(btn, btn->size);
    setbtn_shape_scale(btn, btn->scale);
    btn->is_disabled = str_to_bool(elmt[7]);
    btn->thickness = my_strtof(elmt[8]);
    btn->normal = gettexture_by_name(elmt[9]);
    btn->hovered = gettexture_by_name(elmt[10]);
    btn->pressed = gettexture_by_name(elmt[11]);
    btn->disabled = gettexture_by_name(elmt[12]);
    add_widget(&step[0]->widgets, btn, BUTTON);
    return tl;
}
