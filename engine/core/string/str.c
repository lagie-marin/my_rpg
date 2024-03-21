/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-marin.lagie
** File description:
** my_str_isalpha.c
*/
#include "engine/core.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!my_isletter_isupper(str[i]) && !my_isletter_islow(str[i]))
            return 0;
    return 1;
}

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!my_isletter_islow(str[i]))
            return 0;
    return 1;
}

int my_str_isnum(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_isnum(str[i]) && str[i] != '-')
            return 0;
    return 1;
}

int my_str_isprintable(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] >= 0 && str[i] <= 31) || str[i] == 127)
            return 0;
    return 1;
}

int my_str_isupper(char *str)
{
    for (int i = 0; str[i]; i++)
        if (!my_isletter_isupper(str[i]))
            return 0;
    return 1;
}
