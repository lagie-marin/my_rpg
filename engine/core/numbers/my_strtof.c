/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** my_strtof.c
*/
#include "engine/core.h"

double my_strtof(char *str)
{
    int integer = 0;
    int decimal = 0;

    if (str[0] == '\0')
        return 0.0f;
    integer = my_strtol(str, &str);
    if (str[0] == '\0')
        return (float) integer;
    str++;
    decimal = my_strtol(str, &str);
    return integer + (decimal / pow(10, my_intlen(decimal)));
}
