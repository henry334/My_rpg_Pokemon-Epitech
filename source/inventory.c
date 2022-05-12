/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "./../includes/rpg.h"
#include "./../includes/print.h"

int lets_use_items(game *games, wdw *wind_struct, int x)
{
    if (games->inventorys[x] == ITEM1 && games->in_combat == 2) {
        add_pokemon_inventory(games, games->poke_att);
        games->inventorys[x] = -1;
        my_printf("Used Pokeball at slot %d\n", x);
        sort_array(games);
        return 0;
    } else if (games->inventorys[x] == ITEM2 && games->in_combat >= 1) {
        heal_poke(0, games);
        games->inventorys[x] = -1;
        my_printf("Used Potion at slot %d\n", x);
        sort_array(games);
    }
    return 0;
}

int num_of_item(game *games)
{
    int c;
    int n;

    for (c = 1, n = 0; c < 19; c++) {
        if (games->inventorys[c] != -1)
            n++;
    }
    return n;
}

int place_invnetory(game *games)
{
    int c;

    for (c = 1; c < 19; c++) {
        if (games->inventorys[c] == -1)
            return c;
    }
    return -1;
}

int add_item(game *games, int n)
{
    int c;
    int p;

    if (n == -1) {
        games->inventorys = malloc(sizeof(int) * (19));
        for (c = 0; c < 19; c++) {
            games->inventorys[c] = -1;
        }
        return 0;
    }
    p = place_invnetory(games);
    if (p == -1) {
        my_printf("No more place in inventory\n");
        return 0;
    }
    games->inventorys[p] = n;
    return 1;
}