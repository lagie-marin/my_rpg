/*
** EPITECH PROJECT, 2024
** B-PSU-200-LYN-2-1-minishell1-marin.lagie
** File description:
** letters.c
*/

int my_isletter_islow(char args)
{
    return args >= 97 && args <= 122;
}

int my_isletter_isupper(char args)
{
    return args >= 65 && args <= 90;
}

int my_isletter(char args)
{
    return my_isletter_islow(args) || my_isletter_isupper(args);
}

int my_isnum(char i)
{
    return i >= '0' && i <= '9';
}

int is_alphanumeric(char args)
{
    if (my_isnum(args) || my_isletter(args))
        return 1;
    return 0;
}
