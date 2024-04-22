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

static void apply_texture_img(texture_t *texture, sfColor tint)
{
    sfTexture *texture_img = texture->texture;
    sfImage *image = sfTexture_copyToImage(texture_img);
    sfVector2u size = sfImage_getSize(image);
    sfColor pixel;

    for (ui_t y = 0; y < size.y; y++) {
        for (ui_t x = 0; x < size.x; x++) {
            pixel = sfImage_getPixel(image, x, y);
            pixel.r = (pixel.r * tint.r) / 255;
            pixel.g = (pixel.g * tint.g) / 255;
            pixel.b = (pixel.b * tint.b) / 255;
            pixel.a = (pixel.a * tint.a) / 255;
            sfImage_setPixel(image, x, y, pixel);
        }
    }
    sfTexture_updateFromImage(texture_img, image, 0, 0);
    sfImage_destroy(image);
}

void settexture_name(texture_t *texture, char *name)
{
    if (name[0] == '\0' || name == NULL) {
        put_error("La texture doit avoir un nom\n");
        return;
    }
    texture->name = name;
}

void settexture_img(texture_t *texture, char *img)
{
    if (img != NULL && my_strcmp(img, "none"))
        texture->texture = sfTexture_createFromFile(img, NULL);
    else {
        texture->texture = NULL;
        FREE(img);
    }
}

void settexture_size(texture_t *texture, v2f_t size)
{
    texture->size = size;
}

void settexture_tint(texture_t *texture, sfColor tint)
{
    if (texture->texture != NULL)
        apply_texture_img(texture, tint);
    else
        texture->tint = tint;
}

void settexture_border(texture_t *texture, sfColor border)
{
    texture->border = border;
}
