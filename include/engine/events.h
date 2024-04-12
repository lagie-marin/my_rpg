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
typedef struct events_s events_t;

struct events_s {
    sfEvent event;
    events_fct_t event_handler[24]; //nombre maximum d'event possible
};

/**
 * @brief permet d'initialiser les events utilisé dans l'engine
 */
void init_events(void);

/**
 * @brief permet d'enregistrer les events que l'utilisateur veux utiliser
 * @param evt_type type de l'event à utiliser
 * @param elemtn fonction qui sera appeler
 */
void register_event(sfEventType evt_type, events_fct_t elemtn);

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

#endif
