/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int num_of_pokemon(game *games)
{
    int c = 0;
    int n;

    for (c, n = 0; c < 5; c++) {
        if (games->poke_inventory[c][0] != -1)
            n++;
    }
    return n;
}

void display_invpoke_backend(game *games)
{
    int c;

    for (c = 0; games->poke_inventory[c] != NULL; c++) {
        my_printf("place:%d id:%d xp:%d life:%d\n",
        c + 1, games->poke_inventory[c][0],
        games->poke_inventory[c][1], games->poke_inventory[c][2]);
    }
    my_printf("\n");
}

int get_place(int n, int xp)
{
    if (xp < 300)
        return n;
    else if (xp >= 300 && n < 5)
        return n + 5;
    return n;
}

int place_inv(game *games)
{
    int c;

    for (c = 0; games->poke_inventory[c] != NULL; c++) {
        if (games->poke_inventory[c][0] == -1)
            return c;
    }
    return -1;
}

int add_pokemon_inventory(game *games, int n)
{
    int c;
    if (n == -1) {
        games->poke_inventory = malloc(sizeof(*games->poke_inventory) * 6);
        for (c = 0; c < 5; c++) {
            games->poke_inventory[c] = malloc(sizeof(int) * 3);
            games->poke_inventory[c][0] = -1;
            games->poke_inventory[c][1] = 0;
            games->poke_inventory[c][2] = 0;
        }
        games->poke_inventory[c] = NULL;
        return 0;
    }
    int p = place_inv(games);
    if (p == -1) {
        my_printf("No more place for pokemon\n");
        return 0;
    }
    games->poke_inventory[p][0] = n;
    games->poke_inventory[p][2] = get_poke[n].life;
    return 1;
}