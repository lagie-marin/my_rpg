/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** texture_manager.c
*/
#include "engine/widgets/widgets.h"
#include "engine/ressource.h"
#include "engine/core.h"
#include "engine/window.h"

void settexture_name(texture_t *texture, char *name)
{
    if (name[0] == '\0' || name == NULL) {
        put_error("La texture doit avoir un nom");
        return;
    }
    texture->name = name;
}

void settexture_img(texture_t *texture, char *img)
{
    texture->img = img;
}

void settexture_size(texture_t *texture, v2f_t size)
{
    texture->size = size;
}

void settexture_tint(texture_t *texture, sfColor tint)
{
    texture->tint = tint;
}

void settexture_border(texture_t *texture, sfColor border)
{
    texture->border = border;
}
