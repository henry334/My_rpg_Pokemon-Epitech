/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** manual.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int manual(wdw *wind_struct)
{
    dsply **man = send_manual();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(man, wind_struct, 1);
        int d = event2(wind_struct, man, 1, 3);
        if (d != LOOP) {
            break;
        }
    }
    destroy_sprite(man);
    free_double(man);
    return 0;
}