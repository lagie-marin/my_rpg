/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** init_texture.c
*/
#include "engine/types.h"
#include "engine/widgets/widgets.h"
#include "engine/color.h"
#include "engine/core.h"

static void set_default_normal(void)
{
    texture_t *normal = create_texture("normal");

    settexture_size(normal, (v2f_t) {160.f, 50.f});
    settexture_tint(normal, BEIGE);
    settexture_border(normal, sfBlack);
    append_texture(normal);
}

static void set_default_hovered(void)
{
    texture_t *hovered = create_texture("hovered");

    settexture_size(hovered, (v2f_t) {160.f, 50.f});
    settexture_tint(hovered, GOLD);
    settexture_border(hovered, sfBlack);
    append_texture(hovered);
}

static void set_default_pressed(void)
{
    texture_t *pressed = create_texture("pressed");

    settexture_size(pressed, (v2f_t) {160.f, 50.f});
    settexture_tint(pressed, ORANGE);
    settexture_border(pressed, sfBlack);
    append_texture(pressed);
}

static void set_default_disabled(void)
{
    texture_t *disabled = create_texture("disabled");

    settexture_size(disabled, (v2f_t) {160.f, 50.f});
    settexture_tint(disabled, GREY);
    settexture_border(disabled, sfBlack);
    append_texture(disabled);
}

void init_texture(void)
{
    set_default_normal();
    set_default_hovered();
    set_default_pressed();
    set_default_disabled();
}
