/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** get_window.c
*/
#include "engine/window.h"
#include "engine/types.h"

ui_t get_window_width(void)
{
    return get_engine()->windows->width;
}

ui_t get_window_height(void)
{
    return get_engine()->windows->height;
}

ui_t get_window_fps(void)
{
    return get_engine()->windows->fps;
}

ui_t get_window_bits(void)
{
    return get_engine()->windows->bits;
}
