/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

int is_valide(int t, int l, int m, game *games)
{
    if (m == 0 && t <= 113 || t >= games->max_t)
        return 84;
    if (m == 1 && l <= 76 || l >= games->max_l)
        return 84;
    return 0;
}

void get_y(game *games)
{
    if (games->game[1]->rect.left + 63 > 239) {
        games->game[1]->rect.width = 48;
        games->game[1]->rect.left = 13;
        return;
    } else
        games->game[1]->rect.left += 63;
}

void update_rect_m(game *games, int mode)
{
    if (games->value == mode) {
        get_y(games);
    } else {
        games->game[1]->rect.top = ((62 * mode) + 12);
        get_y(games);
    }
    games->value = mode;
}

void upmp(game *games, int y, int x)
{
    int tt = games->t;
    int ll = games->l;
    int t = games->game[0]->rect.top + y;
    int l = games->game[0]->rect.left + x;
    if (tt != 0 || is_valide(t, l, 0, games) != 0) {
        games->game[1]->vect.y += y;
        games->t += y;
    } else {
        games->game[0]->rect.top += y;
        manager_charizard(games, 0, y, x);
    }
    if (ll != 0 || is_valide(t, l, 1, games) != 0) {
        games->game[1]->vect.x += x;
        games->l += x;
    } else {
        games->game[0]->rect.left += x;
        manager_charizard(games, 1, y, x);
    }
}

int moove(wdw *wind_struct, game *games, int x)
{
    x == 36 ? pause_m(wind_struct, games) : x;
    if (wind_struct->second > 0.025) {
        wind_struct->key_up == PRESS ? up_key(wind_struct, games, x) : x;
        wind_struct->key_down == PRESS ? down_key(wind_struct, games, x) : x;
        wind_struct->key_left == PRESS ? left_key(wind_struct, games, x) : x;
        wind_struct->key_right == PRESS ? right_key(wind_struct, games, x) : x;
        sfClock_restart(wind_struct->clock);
    }
    if (x == wind_struct->key_inventory) {
        use_inventory(wind_struct, games);
    } else if (x == wind_struct->key_poked) {
        pokemon_disp(games, wind_struct);
    }
    return 0;
}