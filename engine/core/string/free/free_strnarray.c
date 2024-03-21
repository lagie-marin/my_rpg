/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** free_strnarray.c
*/
#include "engine/core.h"

int free_strnarray(array arr, int pos)
{
    if (arr == NULL)
        return 1;
    for (int i = pos; arr[i]; i++)
        FREE(arr[i]);
    FREE(arr);
    return 1;
}
