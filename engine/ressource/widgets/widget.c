/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** add_widget.c
*/
#include "engine/widgets/widgets.h"

void add_widget(list_widgets_t **begin, void *widget, widgets_type_t type)
{
    list_widgets_t *new = malloc(sizeof(list_widgets_t));

    if (new == NULL) {
        write(2, "Out of memory\n", 15);
        return;
    }
    new->type = type;
    new->content = widget;
    new->next = *begin;
    new->prev = NULL;
    if (*begin != NULL)
        (*begin)->prev = new;
    *begin = new;
}

void delete_widget(list_widgets_t *begin)
{
    list_widgets_t *tmp;

    while (begin != NULL) {
        tmp = begin;
        begin = begin->next;
        delete[tmp->type](tmp->content);
        FREE(tmp);
    }
}
