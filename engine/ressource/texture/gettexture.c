/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** get.c
*/
#include "engine/core.h"
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/window.h"

texture_t *gettexture_by_name(char *name)
{
    texture_t **textures = get_mapinfo()->textures;

    for (int i = 0; textures[i]; i++)
        if (!my_strcmp(textures[i]->name, name))
            return textures[i];
    return NULL;
}

sfTexture *gettexture(texture_t *texture)
{
    return texture->texture;
}

v2f_t gettexture_size_by_name(char *name)
{
    return gettexture_by_name(name)->size;
}

sfColor gettexture_tint_by_name(char *name)
{
    return gettexture_by_name(name)->tint;
}

sfColor gettexture_border_by_name(char *name)
{
    return gettexture_by_name(name)->border;
}
