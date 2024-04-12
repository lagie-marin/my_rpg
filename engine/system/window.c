/*
** EPITECH PROJECT, 2024
** $dirname
** File description:
** window.c
*/
#include "engine/window.h"

game_engine_t *Game_engine;

static void init_windows(void)
{
    sfVideoMode mode = {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_BIT};
    window_infos_t *windows = malloc(sizeof(window_infos_t));
    char name[16] = "tanker_than_you";

    windows->bits = DEFAULT_BIT;
    windows->fps = DEFAULT_FPS;
    windows->height = DEFAULT_HEIGHT;
    windows->width = DEFAULT_WIDTH;
    windows->window = sfRenderWindow_create(mode, name, WIN_STYLE, NULL);
    Game_engine->windows = windows;
}

static void window_destroy(void)
{
    delete_scan();
    delete_all_canvas(get_mapinfo()->canvas);
    delete_all_canvas(get_mapinfo()->preloaded);
    unload_textures();
    sfRenderWindow_destroy(Game_engine->windows->window);
    FREE(Game_engine->windows);
    FREE(Game_engine);
    Game_engine = NULL;
}

int main(void)
{
    Game_engine = malloc(sizeof(game_engine_t));
    init_events();
    init_map();
    init_texture();
    if (construct() == FAIL)
        return 1;
    init_windows();
    Game_engine->events.event_handler[sfEvtClosed];
    game_loop();
    window_destroy();
    return 0;
}
