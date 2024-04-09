/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** manager.c
*/
#include "engine/widgets/widgets.h"

void (*unload[2])() = {
    &unload_canvas,
    &unload_button
};

void (*delete[2])() = {
    &delete_canvas,
    &delete_button
};
