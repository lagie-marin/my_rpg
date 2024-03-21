/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday08-marin.lagie
** File description:
** my_strdup.c
*/

#include "engine/core.h"

char *my_strdup(char const *src)
{
    char *cpy_src;

    cpy_src = malloc(my_strlen(src) + 1);
    return cpy_src == 0 ? "" : my_strcpy(cpy_src, src);
}
