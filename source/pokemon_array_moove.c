/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void copy_arr(int one, int two, game *games)
{
    int num_1 = games->poke_inventory[one][0];
    int xp_1 = games->poke_inventory[one][1];
    int life_1 = games->poke_inventory[one][2];
    int num_2 = games->poke_inventory[two][0];
    int xp_2 = games->poke_inventory[two][1];
    int life_2 = games->poke_inventory[two][2];
    games->poke_inventory[one][0] = num_2;
    games->poke_inventory[one][1] = xp_2;
    games->poke_inventory[one][2] = life_2;
    games->poke_inventory[two][0] = num_1;
    games->poke_inventory[two][1] = xp_1;
    games->poke_inventory[two][2] = life_1;
}

void poke_moove(game *games, int z)
{
    int n = num_of_pokemon(games);

    z -= n;
    if (z == 0) {
        copy_arr(z, n - 1, games);
        return;
    }
    copy_arr(z, z - 1, games);
}
