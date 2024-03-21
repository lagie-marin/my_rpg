/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-mypaint-maellie.brient-bert
** File description:
** widgets.h
*/
#include "../types.h"
#include "../ressource.h"

#ifndef WIDGETS_H
    #define WIDGETS_H
    //Texture
    #define DEF_SIZE (v2i) {20, 20}
    #define DEF_TINT (sfColor) {60, 60, 60, 1}
    #define DEF_BORDER (sfColor) {0, 0, 0, 1}
typedef enum widgets_type_s widgets_type;
typedef enum cursor_s cursor_t;
typedef enum search_s search_t;
typedef enum combo_elmt_s combo_elmt_t;
typedef struct list_widgets_s list_widgets_t;
typedef struct texture_s texture_t;
typedef struct canvas_s canvas_t;
typedef struct combos_s combos_t;
typedef struct button_s button;

enum widgets_type_s {
    CANVAS,
    COMBO,
    BUTTON
};

enum cursor_s {
    NONE_CURSOR, /**Aucun curseur*/
    DEFAULT, /**Curseur par defaut*/
    TEXT_EDIT_BEAM, /**Curseur en mode d'édition de text*/
    RESIZE_LEFT_RIGHT, /**Curseur de redimensionnement gauche droite*/
    RESIZE_UP_DOWN, /**Curseur de redimensionnement haut bas*/
    RESIZE_SOUTH_EAST, /**Curseur de redimensionnement sud est*/
    RESIZE_SOUTH_WEST, /**Curseur de redimensionnement sud ouest*/
    CARDINAL_CROSS, /**Curseur en mode cardinal*/
    CROSSHAIRS, /**Curseur en mode viseur*/
    HAND, /**Curseur en mode main*/
    GRAB_HAND, /**Curseur en mode main semi fermé*/
    GRAB_HAND_CLOSED, /**Curseur en mode main fermé*/
    SLASHED_CIRCLE, /**Curseur en mode Interdit*/
    EYE_DROPPER /**Curseur en mode pipette*/
};

enum search_s {
    NAME,
    POS_MV,
    POS
};

enum combo_elmt_s {
    NAME_CB,
    POS_CB,
    SIZE,
    OPTIONS,
    SELECTED,
    DISPLAY_ARROW,
    TEXTURE
};

struct list_widgets_s {
    widgets_type type;
    void *content;
    list_widgets_t *next;
    list_widgets_t *prev;
};

struct texture_s {
    char *name;
    char *img;
    v2i size;
    sfColor tint;
    sfColor border;
};

struct canvas_s {
    char *name;
    v2i pos;
    v2f size;
    list_widgets_t *widgets;
};

struct combos_s {
    char *name;
    v2f pos;
    v2f size;
    array option;
    int selected_opt;
    gbool display_arrow;
    texture_t *normal;
    texture_t *hovered;
    texture_t *pressed;
    texture_t *disabled;
};

struct button_s {
    char *name;
    v2f pos;
    v2f size;
    v2f scale;
    gbool is_interactive;
};

void add_widget(list_widgets_t **begin, void *widget, widgets_type type);
void unload_widget(list_widgets_t *begin);

canvas_t **add_step(canvas_t **step, canvas_t *new_step);
canvas_t **rm_step(canvas_t **step);
int len_step(canvas_t **step);

sload gmap_parse_canvas(char *line, canvas_t ***step, sload tl);
canvas_t *create_canvas(char *name);
void setcanvas_name(canvas_t *canvas, char *name);
void setcanvas_pos(canvas_t *canvas, v2i pos);
void setcanvas_size(canvas_t *canvas, v2f size);
void setcanvas_widget(canvas_t *canvas, void *widget);
void setcurrent_canvas(int x, int y);
canvas_t *getcanvas_name(char *name);
v2i getcanvas_pos_by_name(char *name);
v2f getcanvas_size_by_name(char *name);
list_widgets_t *getcanvas_widget_by_name(char *name);
canvas_t *getcanvas_atposition(int x, int y);
void unload_all_canvas(canvas_t **canvas);
void unload_canvas(canvas_t *canvas);

sload gmap_parse_combo(char *line, canvas_t **step, sload tl);
void setcombos_name(combos_t *combos, char *name);
void setcombos_pos(combos_t *combos, v2f pos);
void setcombos_size(combos_t *combos, v2f size);
void setcombos_options(combos_t *combos, array options, int selected_opt);
void setcombos_display_arrow(combos_t *combos, gbool display);

texture_t *create_texture(char *name);
void settexture_name(texture_t *texture, char *name);
void settexture_img(texture_t *texture, char *img);
void settexture_size(texture_t *texture, v2i size);
void settexture_tint(texture_t *texture, sfColor tint);
void settexture_border(texture_t *texture, sfColor border);
void append_texture(texture_t *texture);
texture_t *gettexture_by_name(char *name);
char *gettexture_img_by_name(char *name);
v2i gettexture_size_by_name(char *name);
sfColor gettexture_tint_by_name(char *name);
sfColor gettexture_border_by_name(char *name);
void unload_textures(void);
#endif
