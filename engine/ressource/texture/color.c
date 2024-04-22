/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** color.c
*/

#include "engine/core.h"

sfColor color(int r, int g, int b, int a)
{
    return (sfColor) {r, g, b, a};
}

