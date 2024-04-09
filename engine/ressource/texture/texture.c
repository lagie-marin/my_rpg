/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** texture.c
*/
#include "engine/widgets/widgets.h"
#include "engine/ressource.h"
#include "engine/core.h"
#include "engine/window.h"

static int get_nb_texture(void)
{
    texture_t **textures = get_mapinfo()->textures;
    int len = 0;

    for (int i = 0; textures[i]; i++)
        len++;
    return len;
}

static sfColor get_rgba(char *str)
{
    ui8_t r = my_strtol(&str[1], &str);
    ui8_t g = my_strtol(&str[1], &str);
    ui8_t b = my_strtol(&str[1], &str);
    ui8_t a = my_strtol(&str[1], &str);

    return (sfColor) {r, g, b, a};
}

texture_t *create_texture(char *name)
{
    texture_t *texture = malloc(sizeof(texture_t));

    texture->name = name;
    texture->img = NULL;
    texture->size = (v2f_t) {20, 20};
    texture->tint = DEF_TINT;
    texture->border = DEF_BORDER;
    return texture;
}

void append_texture(texture_t *texture)
{
    texture_t **textures = get_mapinfo()->textures;
    texture_t **new = malloc((get_nb_texture() + 2) * sizeof(texture_t *));
    int i = 0;

    for (i = 0; textures[i]; i++)
        new[i] = textures[i];
    new[i] = texture;
    new[i + 1] = NULL;
    FREE(textures);
    get_mapinfo()->textures = new;
}

void unload_textures(void)
{
    texture_t **textures = get_mapinfo()->textures;

    for (int i = 0; textures[i]; i++) {
        if (i > 3)
            FREE(textures[i]->name);
        FREE(textures[i]->img);
        FREE(textures[i]);
    }
    FREE(textures);
    FREE(get_mapinfo());
}

sload_t gmap_parse_texture(char *line)
{
    array_t element = my_strtok(&line[8], ';');
    v2f_t size = {my_atoi(element[2]), my_atoi(element[3])};
    texture_t *new = create_texture(element[0]);

    settexture_img(new, element[1]);
    settexture_size(new, size);
    settexture_tint(new, get_rgba(element[4]));
    settexture_border(new, get_rgba(element[5]));
    free_strnarray(element, 2);
    append_texture(new);
    return NONE;
}
