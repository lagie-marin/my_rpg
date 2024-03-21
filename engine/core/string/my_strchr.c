/*
** EPITECH PROJECT, 2023
** B-PSU-100-LYN-1-1-myls-marin.lagie
** File description:
** my_strchr.c
*/
#include "engine/core.h"

char *my_strchr(char *str, char ch)
{
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == ch)
            return &str[i];
    return 0;
}
