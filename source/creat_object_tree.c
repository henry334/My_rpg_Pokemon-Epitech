/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

char *get_item(int n)
{
    if (n == ITEM1)
        return "./ressources/inventory/objet/poke.png";
    if (n == ITEM2)
        return "./ressources/inventory/objet/pot.png";
    return "./ressources/inventory/objet/poke.png";
}

dsply **creat_speak(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/sprite/menu_sprite/speak.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 50, 50});
    save[1] = NULL;
    return save;
}

dsply **creat_shop(void)
{
    dsply **save = malloc(sizeof(*save) * 3);
    save[0] = create_object("./ressources/shop/poke.png",
    (sfVector2f){1, 230}, (sfIntRect){0, 0, 325, 520});
    save[1] = create_object("./ressources/shop/pot.png",
    (sfVector2f){3, 230}, (sfIntRect){0, 0, 325, 520});
    save[2] = NULL;
    return save;
}

dsply **creat_inventory_item(game *games)
{
    int l;
    int c;
    int x = 355;
    int y = 270;

    dsply **save = malloc(sizeof(*save) * (num_of_item(games) + 2));
    save[0] = create_object(get_item(1),
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 0, 0});
    for (l = 1, c = 1; l < 19; l++) {
        if (games->inventorys[l] != -1) {
            y = c == 7 || c == 13 ? y + 69 : y;
            x = c == 7 || c == 13 ? 352 : x;
            save[c] = create_object(get_item(games->inventorys[l]),
            (sfVector2f){x, y}, (sfIntRect){0, 0, 52, 52});
            x += 65;
            c++;
        }
    }
    save[c] = NULL;
    return save;
}

dsply **creat_pokemon(game *games)
{
    int l;
    int c;
    int y = 130;
    int n = num_of_pokemon(games);

    dsply **save = malloc(sizeof(*save) * (n + 2));
    for (l = 0, c = 0; l < 5; l++) {
        if (games->poke_inventory[l][0] != -1) {
            save[c] = create_object(
            get_poke[get_place(games->poke_inventory[l][0],
            games->poke_inventory[l][1])].sprite_o, (sfVector2f){299, y},
            get_poke[get_place(games->poke_inventory[l][0],
            games->poke_inventory[l][1])].rect);
            y += 90;
            c++;
        }
    }
    save[c] = NULL;
    return save;
}