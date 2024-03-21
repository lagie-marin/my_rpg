/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-navy-nathan.fievet
** File description:
** free_strarray.c
*/
#include "engine/core.h"

int free_strarray(array arr)
{
    if (arr == NULL)
        return 1;
    for (int i = 0; arr[i] != NULL; i++)
        FREE(arr[i]);
    FREE(arr);
    return 1;
}
