/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create_button.c
*/
#include "engine/widgets/widgets.h"
#include "engine/window.h"
#include "engine/events.h"

button_t *create_button(char *name)
{
    button_t *button = malloc(sizeof(button_t));

    button->name = name;
    button->disabled = FALSE;
    button->btn_shape = sfRectangleShape_create();
    setbtn_shape(button, "normal");
    button->normal = Game_engine->map_info->textures[0];
    button->hovered = Game_engine->map_info->textures[1];
    button->pressed = Game_engine->map_info->textures[2];
    button->disabled = Game_engine->map_info->textures[3];
    button->thickness = 2.f;
    button->fhovered = &default_hovered;
    button->fpressed = &default_pressed;
    button->freleased = &default_released;
    return button;
}
