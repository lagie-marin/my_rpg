/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-marin.lagie
** File description:
** my_str_to_word_array.c
*/

#include "engine/core.h"

static int word_count(const char *c)
{
    int count = 1;

    if (c[0] == '\0')
        return 0;
    for (int i = 0; c[i]; i++)
        if (my_isspace(c[i]) && i > 0 && IS_CARACT(c[i - 1]))
            count++;
    return count;
}

static int len_word(const char *str, int i)
{
    int x = i;

    while (IS_CARACT(str[x]))
        x++;
    return x - i;
}

array my_str_to_word_array(const char *str)
{
    int nb_word = word_count(str);
    array word_array = malloc(sizeof(char *) * (nb_word + 1));
    int x = 0;
    int y = 0;
    int i = 0;

    for (; y < nb_word && nb_word > 0; y++) {
        i = 0;
        while (my_isspace(str[x]))
            x++;
        word_array[y] = my_memset(word_array[y], '\0', len_word(str, x) + 1);
        for (; str[x] != '\0' && IS_CARACT(str[x]); x++) {
            word_array[y][i] = str[x];
            word_array[y][i + 1] = '\0';
            i++;
        }
    }
    word_array[nb_word] = NULL;
    return word_array;
}
