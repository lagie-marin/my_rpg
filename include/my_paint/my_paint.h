/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_paint
*/


#ifndef MY_PAINT_H_
    #define MY_PAINT_H_
    #include "../engine/types.h"
    #include "../engine/widgets/widgets.h"
typedef struct brush_s {
    texture_t line;
    sfColor color;
    v2i size;
}brush_t;

void paint(sfRenderWindow *window, sfRectangleShape *brush);

#endif
