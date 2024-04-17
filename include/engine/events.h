/*
** EPITECH PROJECT, 2024
** Graphitech-Editor
** File description:
** events.h
*/

#include "core.h"
#include "widgets/widgets.h"
#ifndef EVENTS_H
    #define EVENTS_H

typedef enum type_event_e type_event_t;
typedef void (*events_fct_t)();

enum type_event_e {
    EVT_MOVE,
    EVT_PRESSED,
    EVT_RELEASED
};

/**
 * @brief permet d'initialiser les events utilisé dans l'engine
 * @param events_fct_t return array of function
 */
events_fct_t *get_events(void);

/**
 * @brief permet de gérer les différents event et de dispatcher les
 * événement dans les différentes fonctions qui leurs sera attribuer
 */
void event_manager(void);

/**
 * @brief event par default quand la souris passe par dessus un bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event de la souris qui bouge
 */
void default_hovered(button_t *button, sfMouseMoveEvent mouse);

/**
 * @brief event par default quand la souris n'est plus au dessus d'un bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event de la souris qui bouge
 */
void default_unhovered(button_t *button, sfMouseMoveEvent mouse);

/**
 * @brief event par default quand la souris est presser sur le bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event du bouton de la souris
 */
void default_pressed(button_t *button, sfMouseButtonEvent mouse);

/**
 * @brief event par default quand la souris est relacher sur le bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event du bouton de la souris
 */
void default_released(button_t *button, sfMouseButtonEvent mouse);

/**
 * @brief est appeler pour fermer la fenetre
 * @param event définie le système de l'event et ces paramètre
 */
void evt_closed(sfEvent event);

/**
 * @brief est appeler quand le boutton de la souris est presse
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_btn_pressed(sfEvent event);

/**
 * @brief est appeler quand le bouton de la souris est relache
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_btn_released(sfEvent event);

/**
 * @brief est appeler quand la souris est déplacE
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_moved(sfEvent event);

/**
 * @brief Get the events move object
 * @return events_fct_t *
 */
events_fct_t *get_events_move(void);

/**
 * @brief Permet d'intéragir avec les widgets, cette fonction permet d'avoir
 * tout les types d'interaction avec les widgets
 * @param widget widget actuelle
 * @param event définie le système de l'event et ces paramètre
 * @param type type d'interaction
 */
void interact_widget(list_widgets_t *widget, sfEvent event, type_event_t type);
#endif
