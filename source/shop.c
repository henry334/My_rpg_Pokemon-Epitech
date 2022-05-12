/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int action(wdw *wind_struct, game *games, int p)
{
    int money = wind_struct->money;
    if (p == ITEM1 && money >= 200 && add_item(games, ITEM1) == 1) {
        wind_struct->money -= 200;
        my_printf("Bought a pokeball\n");
    } else if (p == ITEM2 && money >= 300 && add_item(games, ITEM2) == 1) {
        wind_struct->money -= 300;
        my_printf("Bought a potion\n");
    }
    sfText_setString(games->money[1]->txt, my_intchar(wind_struct->money));
    return -1;
}

int get_interaction(wdw *wind_struct, game *games, int p)
{
    int x;

    x = event2(wind_struct, games->game, 0, 3);
    if (x == wind_struct->key_up1)
        return ITEM1;
    else if (x == wind_struct->key_down1)
        return ITEM2;

    switch (x) {
        case 4:
            return EXIT_FUNC;
        case 36:
            pause_m(wind_struct, games);
            break;
        case 58:
            return 3;
    }
    return LOOP;
}

int shop(wdw *wind_struct, game *games)
{
    int z;
    int p;

    p = 0;
    dsply **shop = creat_shop();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(games->game, wind_struct, 1);
        sfRenderWindow_drawSprite(wind_struct->window, shop[p]->sp, NULL);
        display_text(games->money, wind_struct);
        z = get_interaction(wind_struct, games, p);
        if (z == EXIT_FUNC)
            break;
        else if (z == 3)
            action(wind_struct, games, p);
        else
            p = z != LOOP ? z : p;
    }
    destroy_sprite(shop);
    free_double(shop);
    return 0;
}