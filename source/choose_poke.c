/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"

int get_onepoke(wdw *wind_struct, dsply **tuto)
{
    int x = event2(wind_struct, tuto, 0, 3);
    switch (x) {
        case 0:
            return x;
        case 1:
            return x;
        case 2:
            return x;
        case 3:
            return x;
        case 4:
            return x;
        default:
            break;
    }
    return LOOP;
}

int choose_poke(wdw *wind_struct, dsply **tuto)
{
    int x = LOOP;
    text **choose = creat_end_tuto();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        display_sprite(tuto, wind_struct, 1);
        display_text(choose, wind_struct);
        anime_tuto(wind_struct, tuto);
        x = get_onepoke(wind_struct, tuto);
        if (x != LOOP) {
            break;
        }
    }
    destroy_text(choose);
    free_double_text(choose);
    return x;
}