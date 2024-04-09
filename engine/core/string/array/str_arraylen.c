/*
** EPITECH PROJECT, 2024
** B-PSU-100-LYN-1-1-navy-nathan.fievet
** File description:
** str_arraylen.c
*/
#include "engine/core.h"

int str_arraylen(array_t src)
{
    int len = 0;

    if (src == NULL)
        return 0;
    while (src[len])
        len++;
    return len;
}
