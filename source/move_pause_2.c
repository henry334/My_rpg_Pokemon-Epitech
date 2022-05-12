/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** move_pause_2.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int enter_2(wdw *wind_struct, dsply **pause, game *games, text **which)
{
    int t;
    if (pause[0]->rect.top == 852 &&
    pause[0]->rect.left == 1080)
        sfRenderWindow_close(wind_struct->window);
    else if (pause[0]->rect.top == 1660 &&
    pause[0]->rect.left == 0) {
        pause[0]->rect.left += 1080;
        display_sprite(pause, wind_struct, 0);
        display_text(which, wind_struct);
        wind_struct->back_menu = 1;
        return EXIT_FUNC;
    }
    return LOOP;
}
