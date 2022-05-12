/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void display_sprite(dsply **struc, wdw *wind_struct, int d)
{
    if (d == 1) {
        sfRenderWindow_display(wind_struct->window);
        sfRenderWindow_clear(wind_struct->window, sfBlack);
    }
    for (int c = 0; struc[c] != NULL; c++) {
        sfSprite_setTextureRect(struc[c]->sp, struc[c]->rect);
        sfSprite_setPosition(struc[c]->sp, struc[c]->vect);
        sfRenderWindow_drawSprite(wind_struct->window, struc[c]->sp, NULL);
    }
}

void display_text(text **struc, wdw *wind_struct)
{
    for (int c = 0; struc[c] != NULL; c++) {
        sfRenderWindow_drawText(wind_struct->window, struc[c]->txt, NULL);
    }
}

void display_invisible(dsply **invisible, wdw *wind_struct)
{
    for (int c = 0; invisible[c] != NULL; c++) {
        sfRenderWindow_drawSprite(wind_struct->window, invisible[c]->sp, NULL);
    }
}

void display_icone(dsply **invisible, wdw *wind_struct)
{
    for (int c = 0; invisible[c] != NULL; c++) {
        sfRenderWindow_drawSprite(wind_struct->window, invisible[c]->sp, NULL);
    }
}