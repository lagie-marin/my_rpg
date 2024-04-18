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
    #define DEF_TINT color(60, 60, 60, 1)
    #define DEF_BORDER color(0, 0, 0, 1)

typedef enum state_e state_t;
typedef enum widgets_type_s widgets_type_t;
typedef enum cursor_s cursor_t;
typedef enum search_s search_t;
typedef enum combo_elmt_s combo_elmt_t;
typedef struct list_widgets_s list_widgets_t;
typedef struct texture_s texture_t;
typedef struct canvas_s canvas_t;
typedef struct combos_s combos_t;
typedef struct button_s button_t;
typedef void (*fhovered_t)(button_t *button, sfMouseMoveEvent mouse);
typedef void (*fpressed_t)(button_t *button, sfMouseButtonEvent mouse);
typedef void (*freleased_t)(button_t *button, sfMouseButtonEvent mouse);
typedef void (*load_t)();
typedef void (*unload_t)();
typedef void (*delete_t)();
typedef gbool_t (*widgets_t)();

enum state_e {
    NONE = -1,
    NORMAL,
    HOVERED,
    PRESSED
};

enum widgets_type_s {
    CANVAS,
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
    widgets_type_t type;
    void *content;
    list_widgets_t *next;
    list_widgets_t *prev;
};

struct texture_s {
    char *name;
    char *img;
    v2f_t size;
    sfColor tint;
    sfColor border;
};

struct canvas_s {
    char *name;
    v2i_t pos;
    v2f_t size;
    list_widgets_t *widgets;
    gbool_t visible;
};

struct combos_s {
    char *name;
    v2f_t pos;
    v2f_t size;
    array_t option;
    int selected_opt;
    gbool_t display_arrow;
    texture_t *normal;
    texture_t *hovered;
    texture_t *pressed;
    texture_t *disabled;
};

struct button_s {
    char *name;
    gbool_t is_disabled;
    v2f_t pos;
    v2f_t size;
    v2f_t scale;
    state_t state;
    sfRectangleShape *btn_shape;
    texture_t *normal;
    texture_t *hovered;
    texture_t *pressed;
    texture_t *disabled;
    float thickness;
    fhovered_t fhovered;
    fpressed_t fpressed;
    freleased_t freleased;
};

/**
 * @brief Permet d'ajouter un widget dans l'interface
 * @param begin la liste du widget qui est contenue dans le canvas
 * @param widget le widget que vous voulez ajouter
 * @param type le type du widget
 */
void add_widget(list_widgets_t **begin, void *widget, widgets_type_t type);

/**
 * @brief permet de supprimer défénitivement les widgets
 * @param begin la liste des widgets qui se trouve dans le canvas
 */
void delete_widget(list_widgets_t *begin);

/**
 * @brief permet de récuperer le content du widget
 * @param widget le widget actuel
 * @return void*
 */
void *getcontent(list_widgets_t *widget);

/**
 * @brief permet d'ajouter les étates au niveau des canvas et permet
 * d'ajouter les widgets dans les bon canvas. La méthode utilisé: Pile,
 * premier ajouter dernier sortie
 * @param step étape actuelle
 * @param new_step nouveau canvas à ajouter dans la step
 * @return canvas_t** retourne les nouvelles étapes
 */
canvas_t **add_step(canvas_t **step, canvas_t *new_step);

/**
 * @brief permet de retirer la dernière étape lors du parsing
 * @param step les étapes actuelles
 * @return canvas_t** retourne les nouvelles étapes
 */
canvas_t **rm_step(canvas_t **step);

/**
 * @brief permet de récupérer le nombre d'étape actuelle
 * @param step les étapes actuelles
 * @return int la taille des étapes
 */
int len_step(canvas_t **step);

/**
 * @brief permet de parser les canvas avec leurs arguments et d'ajouter le
 * canvas dans l'interface qui permettera ensuite d'afficher les différents
 * widgets.
 * @param line la ligne qui contient les différents arguments
 * @param step les étapes actuelles
 * @param tl l'étape dans le chargement
 * @return sload_t tl
 */
sload_t gmap_parse_canvas(char *line, canvas_t ***step, sload_t tl);

/**
 * @brief Crée un canvas avec le nom qu'on lui a donnée ainsi que des
 * valeurs pas defaut
 * @param name nom du canvas
 * @return canvas_t* retourne le canvas
 */
canvas_t *create_canvas(char *name);

/**
 * @brief Définir le nom du canvas
 * @param canvas canvas à modifier
 * @param name nouveau nom du widget
 */
void setcanvas_name(canvas_t *canvas, char *name);

/**
 * @brief Définir les positions du canvas
 * @param canvas canvas à modifier
 * @param pos nouvelle position du canvas
 */
void setcanvas_pos(canvas_t *canvas, v2i_t pos);

/**
 * @brief Définir la taille du canvas
 * @param canvas canvas à modifier
 * @param size nouvelle taille
 */
void setcanvas_size(canvas_t *canvas, v2f_t size);

/**
 * @brief Permet d'ajouter un widget au canvas
 * @param canvas Le canvas où le widget dois être ajouter
 * @param widget le widget à ajouter
 */
void setcanvas_widget(canvas_t *canvas, void *widget);

/**
 * @brief Récupère le canvas à partir de son nom
 * @param name nom du canvas
 * @return canvas_t* NULL | canvas
 */
canvas_t *getcanvas_name(char *name);

/**
 * @brief Récupère la position du canvas à partir de son nom
 * @param name nom du canvas
 * @return v2i_t {-1, -1} | position du canvas
 */
v2i_t getcanvas_pos_by_name(char *name);

/**
 * @brief Récupère la taille du canvas à partir de son nom
 * @param name nom du canvas
 * @return v2f_t {-1.0, -1.0} | taille du canvas
 */
v2f_t getcanvas_size_by_name(char *name);

/**
 * @brief Récupère les widgets qui se trouve dans le canvas avec son nom
 * @param name nom du canvas
 * @return list_widgets_t* NULL | Widget
 */
list_widgets_t *getcanvas_widget_by_name(char *name);

/**
 * @brief Vérifie si le canvas est dans les coordonées donnée.
 * @param x Coordonnée x
 * @param y Coordonnée y
 * @param canvas canvas à vérifier
 * @return gbool_t FALSE | TRUE
 */
gbool_t atposition_contain_canvas(int x, int y, canvas_t *canvas);

/**
 * @brief Charge le canvas ainsi que son contenue
 * @param canvas canvas à charger
 */
void load_canvas(canvas_t *canvas);

/**
 * @brief décharge le canvas ainsi que son contenue
 * @param canvas canvas à décharger
 */
void unload_canvas(canvas_t *canvas);

/**
 * @brief supprime tout les canvas de l'interface ainsi que son contenue
 * @param canvas canvas à supprimer
 */
void delete_all_canvas(canvas_t **canvas);

/**
 * @brief supprime le canvas de l'interface ainsi que son contenue
 * @param canvas canvas à supprimer
 */
void delete_canvas(canvas_t *canvas);

// sload gmap_parse_combo(char *line, canvas_t **step, sload tl);
void setcombos_name(combos_t *combos, char *name);
void setcombos_pos(combos_t *combos, v2f_t pos);
void setcombos_size(combos_t *combos, v2f_t size);
void setcombos_options(combos_t *combos, array_t options, int selected_opt);
void setcombos_display_arrow(combos_t *combos, gbool_t display);

/**
 * @brief Initialise les textures par defaut de l'engine
 */
void init_texture(void);

/**
 * @brief Crée la texture avec des paramètres par defaut
 * est vous donnée le nom de la texture
 * @param name nom de la texture
 * @return texture_t* texture
 */
texture_t *create_texture(char *name);
void settexture_name(texture_t *texture, char *name);
void settexture_img(texture_t *texture, char *img);
void settexture_size(texture_t *texture, v2f_t size);
void settexture_tint(texture_t *texture, sfColor tint);
void settexture_border(texture_t *texture, sfColor border);
void append_texture(texture_t *texture);
texture_t *gettexture_by_name(char *name);
char *gettexture_img_by_name(char *name);
v2f_t gettexture_size_by_name(char *name);
sfColor gettexture_tint_by_name(char *name);
sfColor gettexture_border_by_name(char *name);
void unload_textures(void);

sload_t gmap_parse_button(char *line, canvas_t **step, sload_t tl);
button_t *create_button(char *name);
void setbtn_shape_by_name_texture(button_t *button, char *name_texture);
void setbtn_shape_by_texture(button_t *button, texture_t *texture);
void setbtn_shape_pos(button_t *button, v2f_t pos);
void setbtn_shape_size(button_t *button, v2f_t size);
void setbtn_shape_scale(button_t *button, v2f_t scale);
void setbutton_disabled(button_t *button, gbool_t disabled);
void setbutton_thickness(button_t *button, float thickness);
void setbutton_event_hovered(button_t *button, fhovered_t hovered);
void setbutton_event_pressed(button_t *button, fpressed_t pressed);
void setbutton_event_released(button_t *button, freleased_t released);
gbool_t atposition_contain_button(int x, int y, button_t *button);
void load_button(button_t *button);
void unload_button(button_t *button);
void delete_button(button_t *button);
void draw_button(button_t *button);

load_t load(widgets_type_t type);
unload_t unload(widgets_type_t type);
delete_t delete(widgets_type_t type);

list_widgets_t *at_coordinate(int x, int y);
#endif
