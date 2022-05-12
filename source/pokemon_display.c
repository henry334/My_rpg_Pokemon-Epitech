/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void frees(dsply **poke, text **info_poke, dsply **xx)
{
    destroy_sprite(poke);
    free_double(poke);
    destroy_sprite(xx);
    free_double(xx);
    destroy_text(info_poke);
    free_double_text(info_poke);
}

void get_new_pos_poke(game *games , int n)
{
    int c;
    c = n + 1;
    for (c; games->poke_inventory[c] != NULL; c++) {
        int save1 = games->poke_inventory[c][0];
        int save2 = games->poke_inventory[n][0];
        if (save2 == -1 && save1 != -1) {
            games->poke_inventory[n][0] = save1;
            games->poke_inventory[n][1] = games->poke_inventory[c][1];
            games->poke_inventory[n][2] = games->poke_inventory[c][2];
            games->poke_inventory[c][0] = -1;
            games->poke_inventory[c][1] = 0;
            games->poke_inventory[c][2] = 0;
        }
    }
}

void destroy_poke(int p, game *games)
{
    int c;
    if (num_of_pokemon(games) == 1) {
        my_printf("You cant destroy your last pokemon\n");
        return;
    }
    games->poke_inventory[p][0] = -1;
    for (c = 0; games->poke_inventory[c] != NULL; c++) {
        get_new_pos_poke(games, c);
    }
}

int interact(game *games, wdw *wind_struct, dsply **x)
{
    int n = num_of_pokemon(games);
    int z = event2(wind_struct, x, 0, 2);
    if (z != LOOP) {
        if (z >= n) {
            poke_moove(games, z);
            return -1;
        } else if (z >= 0)
            return z;
    }
    return LOOP;
}

void pokemon_disp(game *games, wdw *wind_struct)
{
    dsply **bg = creat_bg_poke();
    dsply **poke = creat_pokemon(games);
    text **info_poke = creat_poke_text(games);
    dsply **x = creat_x(games);
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_pokemon(wind_struct, x, bg, poke);
        display_text(info_poke, wind_struct);
        int p = interact(games, wind_struct, x);
        if (p != LOOP) {
            p != -1 ? destroy_poke(p, games) : p;
            frees(poke, info_poke, x);
            poke = creat_pokemon(games);
            info_poke = creat_poke_text(games);
            x = creat_x(games);
        } else if (wind_struct->event.type == sfEvtKeyPressed &&
            wind_struct->event.key.code == wind_struct->key_poked
            || wind_struct->event.key.code == 36)
            break;
    }
    free_pokemon_disp(bg, poke, info_poke, x);
}