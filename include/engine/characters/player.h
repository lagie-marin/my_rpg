/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player.h
*/
#include "../ressource.h"
#ifndef PLAYER_H
    #define PLAYER_H

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    int health;
    int speed;
} player_t;

void key_pressed(sfEvent event);
#endif
