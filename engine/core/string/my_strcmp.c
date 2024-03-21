/*
** EPITECH PROJECT, 2017
** strcmp
** File description:
** cmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int x = 0;

    if ((!s1 && !s2))
        return 0;
    if (!s1)
        return -s2[0];
    if (!s2)
        return -s1[0];
    for (x = 0; s1[x] && s2[x] && s1[x] == s2[x]; x++);
    return s1[x] - s2[x];
}
