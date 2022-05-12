/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **creat_charizard(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("ressources/pokemon/front/charizard-shiny.png",
    (sfVector2f){604, 169}, (sfIntRect){0, 0, 128, 120});
    sfSprite_scale(save[0]->sp, (sfVector2f){1.65, 1.65});
    save[1] = NULL;
    return save;
}

dsply **creat_pharmacy(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/dialogue/pharmacy.png",
    (sfVector2f){100, 530}, (sfIntRect){0, 0, 900, 180});
    save[1] = NULL;
    return save;
}

dsply **creat_bg_poke(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    save[1] = NULL;
    return save;
}

dsply **creat_x(game *games)
{
    int c;
    int y = 155;
    int n = num_of_pokemon(games);

    dsply **save = malloc(sizeof(*save) * ((n * 2 )+ 2));
    for (c = 0; c < n; c++) {
        save[c] = create_object("./ressources/sprite/menu_sprite/cross.png",
        (sfVector2f) {250, y}, (sfIntRect) {0, 0, 55, 55});
        y += 90;
    }
    y = 160;
    for (c; c < n * 2; c++) {
        save[c] = create_object("./ressources/sprite/menu_sprite/arrow.png",
        (sfVector2f) {670, y}, (sfIntRect) {0, 0, 53, 53});
        y += 90;
    }
    save[c] = NULL;
    return save;
}