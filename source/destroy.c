/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"

void destroy_sprite(dsply **struct1)
{
    for (int c = 0; struct1[c] != NULL; c++) {
        sfTexture_destroy(struct1[c]->txtu);
        sfSprite_destroy(struct1[c]->sp);
    }
}

void destroy_text(text **struct1)
{
    for (int c = 0; struct1[c] != NULL; c++) {
        sfFont_destroy(struct1[c]->f);
        sfText_destroy(struct1[c]->txt);
    }
}

void destroy_square(square **struct1)
{
    for (int c = 0; struct1[c] != NULL; c++) {
        sfRectangleShape_destroy(struct1[c]->rs);
    }
}

void dest(wdw *windo_struct)
{
    sfMusic_destroy(windo_struct->music);
    sfMusic_destroy(windo_struct->msc_cm);
    sfClock_destroy(windo_struct->clock);
    free_double_char(windo_struct->map);
    return;
}

void des_game(game *games)
{
    destroy_sprite(games->arceus);
    destroy_sprite(games->game);
    destroy_sprite(games->inventory);
    destroy_sprite(games->speak);
    destroy_sprite(games->charizard);
    destroy_sprite(games->vld_quest);
    destroy_text(games->money);
    destroy_text(games->quest);
    free_double(games->speak);
    free_double(games->game);
    free_double(games->inventory);
    free_double(games->charizard);
    free_double_text(games->money);
    free_double_text(games->quest);
    free_double(games->vld_quest);
    free_double(games->arceus);
    for (int c = 0; c < 5; c++)
        free(games->poke_inventory[c]);
    free(games->poke_inventory);
    free(games->inventorys);
}