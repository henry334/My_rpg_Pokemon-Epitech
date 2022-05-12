/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

square *create_square(sfColor color, sfVector2f pos, sfVector2f size)
{
    square *obj = malloc(sizeof(*obj));
    sfRectangleShape *rs = sfRectangleShape_create();
    sfRectangleShape_setSize(rs, size);
    sfRectangleShape_setFillColor(rs, color);
    sfRectangleShape_setPosition(rs, pos);
    obj->fps_m = pos;
    obj->scale = size;
    obj->rs = rs;
    return obj;
}

square **create_fps_square(wdw *wind_struct)
{
    square **squares = malloc(sizeof(*squares) * 3);
    squares[0] = create_square(sfGreen, wind_struct->last, (sfVector2f){4, 5});
    squares[1] = create_square(sfGreen, (sfVector2f){1067, 60},
    (sfVector2f){4, 5});
    squares[2] = NULL;
    return squares;
}
