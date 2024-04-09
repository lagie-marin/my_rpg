/*
** EPITECH PROJECT, 2024
** B-CPE-200-LYN-2-1-robotfactory-marin.lagie
** File description:
** my_strtol.c
*/
#include "engine/core.h"
#include "engine/types.h"

long int my_strtol(char *string, char **end)
{
    long int result = 0;
    gbool_t sign = FALSE;

    while (*string == ' ')
        string++;
    if (*string == '-') {
        sign = TRUE;
        string++;
    }
    while (IS_DIGIT(*string)) {
        result = result * 10 + (*string - '0');
        string++;
    }
    if (end != NULL)
        *end = string;
    if (sign)
        return sign * result;
    return result;
}
