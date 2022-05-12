/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

void heal_poke(int c, game *games)
{
    int z;
    int num;
    int xp;

    num = games->poke_inventory[c][0];
    xp = games->poke_inventory[c][1];
    z = get_place(num, xp);
    games->poke_inventory[c][2] = get_poke[z].life;
}

void heal_all_poke(game *games)
{
    for (int c = 0; games->poke_inventory[c] != NULL; c++) {
        heal_poke(c, games);
    }
}

int interaction(wdw *wind_struct, dsply **pha, game *games)
{
    int x = event2(wind_struct, pha, 0, 3);
    switch (x) {
        case 0:
            heal_all_poke(games);
            return EXIT_FUNC;
        case 1:
            return EXIT_FUNC;
        case 4:
            return EXIT_FUNC;
    }
    return LOOP;
}

void pharmacy(game *games, wdw *wind_struct)
{
    dsply **pha = creat_pharmacy();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(games->game, wind_struct, 1);
        display_sprite(pha, wind_struct, 0);
        if (interaction(wind_struct, pha, games) == EXIT_FUNC)
            break;
    }
    destroy_sprite(pha);
    free_double(pha);
}