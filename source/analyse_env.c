/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void change_rect(game *games, int mode)
{
    games->game[1]->rect.top = ((62 * mode) + 12);
    games->game[1]->rect.left = 13;
    games->value = mode;
}

char *nmm(int code)
{
    for (int c = 0; get_name[c].code != -1; c++) {
        if (code == get_name[c].code)
            return get_name[c].name;
    }
    return my_intchar(code);
}

int event2(wdw *wind_struct, dsply **meny_sp, int st, int op)
{
    while (sfRenderWindow_pollEvent
    (wind_struct->window, &wind_struct->event)) {
        if (wind_struct->ph == MAIN_GAME
        && wind_struct->event.type == sfEvtKeyPressed)
            mooove_gd(wind_struct, meny_sp);
        if (wind_struct->ph == MAIN_GAME
        && wind_struct->event.type == sfEvtKeyReleased)
            mooove_bd(wind_struct, meny_sp);
        switch (wind_struct->event.type) {
            case sfEvtClosed:
                sfRenderWindow_close(wind_struct->window);
                break;
            case sfEvtMouseButtonPressed:
                return play_check(wind_struct, meny_sp, st, op);
            case sfEvtKeyPressed:
                return get_key(wind_struct, op);
        }
    }
    return LOOP;
}
