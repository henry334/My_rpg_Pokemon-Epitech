/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** tuto.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void anime_tuto(wdw *wind_struct, dsply **intro)
{
    if (wind_struct->second > 0.01) {
        intro[2]->rect.left += 84;
        sfClock_restart(wind_struct->clock);
        if (intro[2]->rect.left == 3276) {
            intro[2]->rect.left = 0;
        }
    }
}

int choose_tuto(wdw *wind_struct)
{
    dsply **tmp;
    int x = event2(wind_struct, tmp, 0, 3);
    switch (x) {
        case 57:
            return 1;
        case 4:
            return -1;
    }
    return 0;
}

int my_dialogue(wdw *wind_struct, text **dialogue, int l)
{
    int d = LOOP;
    if (dialogue[l] != NULL) {
        sfRenderWindow_drawText(wind_struct->window, dialogue[l]->txt, NULL);
        d = choose_tuto(wind_struct);
        if (d == 1 || d == -1)
            return d;
        else
            return -2;
    }
    return -1;
}

int conv(wdw *wind_struct, int n)
{
    int l;
    int x;
    dsply **tuto = creat_text();
    text **dialogue = creat_dlg(n);

    l = 0;
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        x = my_dialogue(wind_struct, dialogue, l);
        if (x == -1)
            break;
        else if (x != -2)
            l++;
        sfRenderWindow_display(wind_struct->window);
        sfRenderWindow_drawSprite(wind_struct->window, tuto[0]->sp, NULL);
    }
    destroy_sprite(tuto);
    destroy_text(dialogue);
    free_double(tuto);
    free_double_text(dialogue);
    return 0;
}

int my_tuto(wdw *wind_struct)
{
    int l = 0;
    int x;
    dsply **tuto = send_creat_tuto();
    text **dialogue = send_text_tuto();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        x = my_dialogue(wind_struct, dialogue, l);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        if (x == -1) {
            x = choose_poke(wind_struct, tuto);
            break;
        } else if (x != -2)
            l++;
        display_sprite(tuto, wind_struct, 1);
        anime_tuto(wind_struct, tuto);
    }
    free_tuto(tuto, dialogue);
    return x;
}