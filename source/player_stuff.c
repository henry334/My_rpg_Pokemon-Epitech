/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void get_new_pos(game *games , int n)
{
    int save1;
    int save2;
    int c;

    c = n + 1;
    for (c; c < 19; c++, n++) {
        save1 = games->inventorys[c];
        save2 = games->inventorys[n];
        if (save2 == -1 && save1 != -1) {
            games->inventorys[c] = save2;
            games->inventorys[n] = save1;
        }
    }
}

void sort_array(game *games)
{
    int c;

    for (c = 1; c < 19; c++) {
        get_new_pos(games, c);
    }
}

int use_item(game *games, wdw *wind_struct, dsply **item)
{
    int x = event2(wind_struct, item, 1, 2);
    if (x != LOOP && x > 0 && games->in_combat >= 1) {
        lets_use_items(games, wind_struct, x);
        return x;
    } else if (x < 0) {
        my_printf("Rm item at slot %d\n", x * -1);
        games->inventorys[x * -1] = -1;
        sort_array(games);
        return x * -1;
    }
    return LOOP;
}

void use_inventory(wdw *wind_struct, game *games)
{
    int p;
    dsply **items = creat_inventory_item(games);
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        sfRenderWindow_display(wind_struct->window);
        display_sprite(games->inventory, wind_struct, 0);
        display_sprite(items, wind_struct, 0);
        display_quest(games, wind_struct);
        display_text(games->money, wind_struct);
        p = use_item(games, wind_struct, items);
        if (p != LOOP) {
            free_inventory(items);
            items = creat_inventory_item(games);
        }
        if (wind_struct->event.type == sfEvtKeyPressed &&
        wind_struct->event.key.code == wind_struct->key_inventory
        || wind_struct->event.key.code == 36)
            break;
    }
    free_inventory(items);
    return;
}

char *get_sp(int code, int type)
{
    if (code == 1) {
        if (type == 1) {
            return "./ressources/char/mov/boy_walk.png";
        } else
            return "./ressources/char/mov/boy_throw.png";
    } else if (code == 2) {
        if (type == 1) {
            return "./ressources/char/mov/girl_walk.png";
        } else {
            return "./ressources/char/mov/girl_throw.png";
        }
    }
    return EXIT_ERROR;
}