/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** map_info.c
*/

#include "engine/core.h"
#include "engine/ressource.h"
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/window.h"

map_info_t *get_mapinfo(void)
{
    return get_engine()->map_info;
}

void init_map(void)
{
    get_engine()->map_info = malloc(sizeof(map_info_t));
    my_printf("Init map\n");
    my_printf("Scanning map\n");
    get_mapinfo()->maps = scan("./content");
    get_mapinfo()->textures = malloc(sizeof(texture_t *));
    get_mapinfo()->textures[0] = NULL;
    get_mapinfo()->canvas = malloc(sizeof(canvas_t));
    get_mapinfo()->canvas[0] = NULL;
    get_mapinfo()->actual = NULL;
}
