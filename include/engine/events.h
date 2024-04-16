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

typedef void (*events_fct_t)();

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
void default_hovered(button_t *button, sfMouseMoveEvent *mouse);

/**
 * @brief event par default quand la souris est presser sur le bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event du bouton de la souris
 */
void default_pressed(button_t *button, sfMouseButtonEvent *mouse);

/**
 * @brief event par default quand la souris est relacher sur le bouton
 * @param button le bouton actuel où passe la souris
 * @param mouse event du bouton de la souris
 */
void default_released(button_t *button, sfMouseButtonEvent *mouse);

/**
 * @brief est appeler pour fermer la fenetre
 * @param event définie le système de l'event et ces paramètre
 */
void evt_closed(sfEvent event);

/**
 * @brief est appeler quand le boutton de la souris est pressé
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_btn_pressed(sfEvent event);

/**
 * @brief est appeler quand le bouton de la souris est relaché
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_btn_released(sfEvent event);

/**
 * @brief est appeler quand la souris est déplacé
 * @param event définie le système de l'event et ces paramètre
 */
void evt_mouse_moved(sfEvent event);
#endif
