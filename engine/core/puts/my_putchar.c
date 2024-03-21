/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-marin.lagie
** File description:
** my_putchar.c
*/
#include "engine/core.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
