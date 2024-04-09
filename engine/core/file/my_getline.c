/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-marin.lagie
** File description:
** my_getline.c
*/
#include "engine/core.h"

ssize_t my_getline(array_t input, size_t *len, FILE *stream)
{
    ssize_t bytes = 0;

    FREE(*input);
    *input = NULL;
    bytes = getline(input, len, stream);
    if (*input != NULL)
        (*input)[bytes - 1] = '\0';
    return bytes;
}
