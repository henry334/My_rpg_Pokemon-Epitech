/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** usage.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int pause_up(wdw *wind_struct, dsply **pause)
{
    if (pause[0]->rect.top == 44)
        return LOOP;
    else
        pause[0]->rect.top -= 808;
    return LOOP;
}

int pause_down(wdw *wind_struct, dsply **pause)
{
    if (pause[0]->rect.top == 1660) {
        pause[0]->rect.left = 0;
        return LOOP;
    } else
        pause[0]->rect.top += 808;

    if (pause[0]->rect.top == 1660) {
        pause[0]->rect.left = 0;
    }
    return LOOP;
}

int pause_left(wdw *wind_struct, dsply **pause)
{
    if (pause[0]->rect.left == 0)
        return LOOP;
    else
        pause[0]->rect.left -= 1080;
    return LOOP;
}

int pause_right(wdw *wind_struct, dsply **pause)
{
    if (pause[0]->rect.top == 1660) {
        return LOOP;
    }
    if (pause[0]->rect.left == 1080)
        return LOOP;
    else
        pause[0]->rect.left += 1080;
    return LOOP;
}

int enter(wdw *wind_struct, dsply **pause, game *games, text **which)
{
    if (pause[0]->rect.top == 44 &&
    pause[0]->rect.left == 0) {
        my_printf("Pokemon\n");
        pokemon_disp(games, wind_struct);
    } else if (pause[0]->rect.top == 44 &&
    pause[0]->rect.left == 1080) {
        my_printf("Inventary\n");
        use_inventory(wind_struct, games);
    } else if (pause[0]->rect.top == 852 &&
    pause[0]->rect.left == 0) {
        save_and_load(games, wind_struct, 1);
        my_printf("SAVED\n");
    }
    return enter_2(wind_struct, pause, games, which);
}