/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** setbutton.c
*/
#include "engine/types.h"
#include "engine/widgets/widgets.h"

void setbutton_disabled(button_t *button, gbool_t disabled)
{
    button->is_disabled = disabled;
}

void setbutton_thickness(button_t *button, float thickness)
{
    button->thickness = thickness;
}

void setbutton_event_hovered(button_t *button, fhovered_t hovered)
{
    button->fhovered = hovered;
}

void setbutton_event_pressed(button_t *button, fpressed_t pressed)
{
    button->fpressed = pressed;
}

void setbutton_event_released(button_t *button, freleased_t released)
{
    button->freleased = released;
}
