/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void free_double_text(text **temp)
{
    for (int c = 0; temp[c] != NULL; c++)
        free(temp[c]);
    free(temp);
}

void free_double_char(char **temp)
{
    for (int c = 0; temp[c] != NULL; c++)
        free(temp[c]);
    free(temp);
}

void free_double(dsply **temp)
{
    for (int c = 0; temp[c] != NULL; c++)
        free(temp[c]);
    free(temp);
}

void free_fight(text **text_1, dsply **poke, dsply **fight)
{
    free_double(poke);
    free_double(fight);
    free_double_text(text_1);
}

void display_pokemon(wdw *wind_struct, dsply **x, dsply **bg, dsply **poke)
{
    display_sprite(bg, wind_struct, 1);
    display_sprite(poke, wind_struct, 0);
    display_sprite(x, wind_struct, 0);
}