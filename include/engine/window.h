/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** window.h
*/
#include "core.h"
#include "ressource.h"
#include "events.h"
#include "types.h"
#include "widgets/widgets.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#ifndef WINDOW_H
    #define WINDOW_H
    /**
     * @brief DEFAULT_HEIGHT
     * Valeur par défault de la hauteur de la fenetre du jeu
     */
    #define DEFAULT_HEIGHT 1080

    /**
     * @brief DEFAULT_WIDTH
     * Valeur par défault de la largeur de la fenetre du jeu
     */
    #define DEFAULT_WIDTH 1920

    /**
     * @brief DEFAULT_FPS
     * Valeur par défault des fps de la fenetre du jeu
     */
    #define DEFAULT_FPS 60

    /**
     * @brief DEFAULT_BIT Unité de mesure qui exprime le nombre de couleurs,
     * en bits, pouvant être affiché par un pixel
     */
    #define DEFAULT_BIT 32

    /**
     * @brief WIN_STYLE permet de fermer ou redimentionner la fenetre
     */
    #define WIN_STYLE (sfClose | sfResize)

    /**
     * @brief CREATE_IMG crée une image à partir d'une image
     * @param filename chemin vers le fichier
     * @return sfImage
     */
    #define CREATE_IMG(filename) (sfImage_createFromFile(filename))

    /**
     * @brief GETSIZE_IMG permet de récuperer la taille de l'image
     * @param img Image Object
     * @return sfVector2u
     */
    #define GET_SIZE_IMG(img) (sfImage_getSize(img))

    /**
     * @brief GET_PIXEL_IMG permet de récupèrer les pixels de l'image
     * @param img Image Object
     * @return sfuInt8
     */
    #define GET_PIXEL_IMG(img) (sfImage_getPixelsPtr(img))

    /**
     * @brief SET_ICON permet d'ajouter une icone à sa fenetre
     * @param win Window
     * @param x largeur de l'image en unsigned int
     * @param y hauteur de l'image en unsigned int
     * @param pixels Pointeur vers le tableau de pixels en mémoire
     */
    #define EVT_MS_BTN_P sfEvtJoystickButtonPressed
    #define EVT_MS_BTN_R sfEvtJoystickButtonReleased
    #define SET_ICON(win, x, y, pixels) (sfWindow_setIcon(win, x, y, pixels))
    #define IS_MOUSE_BTN(type) (type >= EVT_MS_BTN_P && EVT_MS_BTN_R)
    #define IS_CLOSED(type)(type == sfEvtClosed)
    #define IS_MOUSE_MV(type)(type == sfEvtMouseMoved)

typedef struct window_infos_s window_infos_t;
typedef struct map_info_s map_info_t;
typedef struct game_engine_s game_engine_t;

struct window_infos_s {
    sfRenderWindow *window;
    ui_t width;
    ui_t height;
    ui_t fps;
    ui_t bits;
};

struct map_info_s {
    maps_t *maps;
    texture_t **textures;
    canvas_t **canvas;
    canvas_t **preloaded;
    canvas_t *actual;
};

struct game_engine_s {
    window_infos_t *windows;
    map_info_t *map_info;
    events_t events;
};

extern game_engine_t *Game_engine;

void init_map(void);
map_info_t *get_mapinfo(void);
void game_loop(void);
status_t construct(void);
void evt_tickrate(void);

/**
 * @brief Get the window width object
 * @return ui
 */
ui_t get_window_width(void);

/**
 * @brief Get the window height object
 * @return ui
 */
ui_t get_window_height(void);

/**
 * @brief Get the window fps object
 * @return ui
 */
ui_t get_window_fps(void);

/**
 * @brief Get the window bits object
 * @return ui<
 */
ui_t get_window_bits(void);
#endif
