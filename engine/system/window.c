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

    windows->bits = DEFAULT_BIT;
    windows->fps = DEFAULT_FPS;
    windows->height = DEFAULT_HEIGHT;
    windows->width = DEFAULT_WIDTH;
    windows->window = sfRenderWindow_create(mode, "my_paint", WIN_STYLE, NULL);
    Game_engine->windows = windows;
}

int main(void)
{
    Game_engine = malloc(sizeof(game_engine_t));
    init_events();
    init_map();
    if (construct() == FAIL)
        return 1;
    init_windows();
    game_loop();
    return 0;
}

void window_destroy(void)
{
    delete_scan();
    unload_all_canvas(get_mapinfo()->canvas);
    unload_all_canvas(get_mapinfo()->preloaded);
    unload_textures();
    sfRenderWindow_destroy(Game_engine->windows->window);
    FREE(Game_engine->windows);
    FREE(Game_engine);
    Game_engine = NULL;
}
