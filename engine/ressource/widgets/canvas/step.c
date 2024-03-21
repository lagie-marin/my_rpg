/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** step.c
*/
#include "engine/widgets/widgets.h"
#include "engine/types.h"
#include "engine/core.h"
#include "engine/ressource.h"

int len_step(canvas_t **step)
{
    int len = 0;

    for (int i = 0; step[i]; i++)
        len++;
    return len;
}

canvas_t **add_step(canvas_t **step, canvas_t *new_step)
{
    int len = len_step(step);
    canvas_t **new = malloc((len + 2) * sizeof(canvas_t));
    int i = 1;

    new[0] = new_step;
    for (; i < len; i++)
        new[i] = step[i];
    FREE(step);
    new[i] = NULL;
    return new;
}

canvas_t **rm_step(canvas_t **step)
{
    int len = len_step(step);
    canvas_t **new;

    if (len == 0)
        return step;
    if (len == 1) {
        step[0] = NULL;
        return step;
    }
    new = malloc(len * sizeof(canvas_t));
    for (int i = 1; step[i]; i++)
        new[i - 1] = step[i];
    new[len] = NULL;
    FREE(step);
    return new;
}
