/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday04-marin.lagie
** File description:
** my_atoi.c
*/
#include "engine/core.h"
#include "engine/types.h"

int my_atoi(char const *str)
{
    int isnumber = 0;
    gbool_t isnegative = FALSE;
    int num = 0;

    if (!my_strcmp(str, "-2147483648"))
        return -2147483648;
    for (int i = 0; str[i] && (IS_DIGIT(str[i]) || isnumber != 1); i++) {
        if (str[i] == 45 && IS_DIGIT(str[i + 1])) {
            isnegative = TRUE;
            i++;
        }
        isnumber = 1;
        num = num * 10 + (str[i] - '0');
    }
    if (isnegative)
        return num * -1;
    return num;
}
