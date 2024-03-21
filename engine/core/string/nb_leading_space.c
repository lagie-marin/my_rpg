/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** nb_leading_space.c
*/
#include "engine/core.h"

int nb_leading_space(char *str)
{
    int len = 0;

    for (int i = 0; str[i] == ' '; i++)
        len++;
    return len;
}
