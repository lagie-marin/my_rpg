/*
** EPITECH PROJECT, 2024
** libs
** File description:
** my_strtok.c
*/
#include "engine/core.h"

static int word_count(const char *c, cc delimiters)
{
    int count = 1;

    for (int i = 0; c[i]; i++)
        if ((c[i] == delimiters && i > 0 && c[i - 1] != delimiters) ||
            (c[i] == '\t' && c[i - 1] != '\t'))
            count++;
    return count;
}

static int len_word(const char *str, int i, cc delimiters)
{
    int x = i;

    while (str[x] && str[x] != delimiters)
        x++;
    return x - i;
}

static int next_carac(const char *str, int i, cc delimiters)
{
    int x = i;

    while (str[x] && str[x] == delimiters)
        x++;
    return x;
}

static void process(char const *str, array arr, int nb_word, cc del)
{
    int word_len = 0;
    int pos_s = 0;
    int pos_t = 0;

    while (pos_t < nb_word) {
        word_len = 0;
        pos_s = next_carac(str, pos_s, del);
        arr[pos_t] = malloc((len_word(str, pos_s, del) + 1) * sizeof(char));
        while (str[pos_s] && str[pos_s] != del) {
            arr[pos_t][word_len] = str[pos_s];
            pos_s++;
            word_len++;
        }
        arr[pos_t][word_len] = '\0';
        pos_s++;
        pos_t++;
    }
    arr[pos_t] = NULL;
}

array my_strtok(const char *str, cc delimiters)
{
    int nb_word = word_count(str, delimiters);
    array word_array = malloc(sizeof(char *) * (nb_word + 1));

    process(str, word_array, nb_word, delimiters);
    return word_array;
}
