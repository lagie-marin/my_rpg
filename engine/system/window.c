/*
** EPITECH PROJECT, 2024
** $dirname
** File description:
** window.c
*/
#include "engine/window.h"


static void init_windows(void)
{
    sfVideoMode mode = {DEFAULT_WIDTH, DEFAULT_HEIGHT, DEFAULT_BIT};
    window_infos_t *windows = get_engine()->windows;
    char name[49] = "The Ancient Secrets: The Secrets of the Eternity";

    my_printf("Init windows\n");
    windows->window = sfRenderWindow_create(mode, name, WIN_STYLE, NULL);
}

static void window_destroy(void)
{
    my_printf("Assets offloading\n");
    delete_scan();
    delete_all_canvas(get_mapinfo()->canvas);
    unload_textures();
    if (get_engine()->windows != NULL)
        sfRenderWindow_destroy(get_engine()->windows->window);
    FREE(get_engine()->windows);
    FREE(get_engine());
}

game_engine_t *get_engine(void)
{
    static game_engine_t *engine = NULL;
    static gbool_t is_init = FALSE;
    static window_infos_t *windows;

    if (is_init == TRUE)
        return engine;
    engine = malloc(sizeof(window_infos_t));
    windows = malloc(sizeof(window_infos_t));
    my_printf("Preload windows\n");
    windows->bits = DEFAULT_BIT;
    windows->fps = DEFAULT_FPS;
    windows->height = DEFAULT_HEIGHT;
    windows->width = DEFAULT_WIDTH;
    windows->window = NULL;
    engine->windows = windows;
    is_init = TRUE;
    return engine;
}

int main(void)
{
    get_engine();
    init_map();
    init_texture();
    if (construct() == FAIL)
        return 1;
    init_windows();
    game_loop();
    window_destroy();
    return 0;
}
