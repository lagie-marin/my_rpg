/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** my_strlen.c
*/
#include "engine/core.h"

int my_strlen(const char *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++)
        len++;
    return len;
}
