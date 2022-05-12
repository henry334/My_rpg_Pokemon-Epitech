/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** do_we_fight.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int random_poke(int l)
{
    int x = rand() % l;
    return x;
}

int do_we_fight(game *games, wdw *wind_struct)
{
    int z;
    int x = rand() % 45;

    if (x == 1) {
        games->in_combat = 1;
        z = random_poke(5);
        games->poke_att = z;
        games->poke_life = get_poke[z].life;
        return intro_fight(wind_struct, games, z);
    }
    return 0;
}