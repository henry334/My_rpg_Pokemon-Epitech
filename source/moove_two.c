/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

void left_key(wdw *wind_struct, game *games, int x)
{
    update_rect_m(games, 1);
    if (collision(wind_struct, games, 0, -1) == 0)
        return;
    else if (wind_struct->s_l == 1) {
        wind_struct->pos_x += -1;
        wind_struct->s_l = 0;
    } else
        wind_struct->s_l += 1;
    upmp(games, 0, -3);
}

void right_key(wdw *wind_struct, game *games, int x)
{
    update_rect_m(games, 2);
    if (collision(wind_struct, games, 0, 1) == 0)
        return;
    else if (wind_struct->s_r == 1) {
        wind_struct->pos_x += 1;
        wind_struct->s_r = 0;
    } else
        wind_struct->s_r += 1;
    upmp(games, 0, 3);
}

void up_key(wdw *wind_struct, game *games, int x)
{
    update_rect_m(games, 3);
    if (collision(wind_struct, games, -1, 0) == 0)
        return;
    else if (wind_struct->s_u == 1) {
        wind_struct->pos_y += -1;
        wind_struct->s_u = 0;
    } else
        wind_struct->s_u += 1;
    upmp(games, -3, 0);
}

void down_key(wdw *wind_struct, game *games, int x)
{
    update_rect_m(games, 0);
    if (collision(wind_struct, games, 1, 0) == 0)
        return;
    else if (wind_struct->s_d == 1) {
        wind_struct->pos_y += 1;
        wind_struct->s_d = 0;
    } else
        wind_struct->s_d += 1;
    upmp(games, 3, 0);
}
