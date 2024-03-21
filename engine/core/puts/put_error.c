/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** put_error.c
*/
#include "engine/core.h"

int put_error(char *str)
{
    write(2, str, LEN(str));
    return 84;
}
