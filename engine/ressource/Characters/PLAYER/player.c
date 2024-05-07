/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** player.c
*/

#include "engine/characters/player.h"

player_t *create_player(char *texture_path)
{
    player_t *player = malloc(sizeof(player_t));

    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    player->texture = sfTexture_createFromFile(texture_path, NULL);
    player->sprite = sfSprite_create();
    player->position = (sfVector2f){0, 0};
    player->health = 100;
    player->speed = 10;
    if (!player)
        return NULL;
    if (!player->texture) {
        free(player);
        return NULL;
    }
    return player;
}

void move_player(player_t *player, sfVector2f direction)
{
    player->position.x += direction.x * player->speed;
    player->position.y += direction.y * player->speed;
    sfSprite_setPosition(player->sprite, player->position);
}

void draw_player(sfRenderWindow* window, player_t *player)
{
    sfRenderWindow_drawSprite(window, player->sprite, NULL);
}

void destroy_player(player_t *player)
{
    sfTexture_destroy(player->texture);
    sfSprite_destroy(player->sprite);
    free(player);
}
