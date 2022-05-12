/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int get_key(wdw *wind_struct, int op)
{
    if (op == 2)
        return LOOP;
    return wind_struct->event.key.code;
}

int play_check(wdw *wind_struct, dsply **struc, int st, int op)
{
    if (op == 3)
        return LOOP;
    int k = wind_struct->event.mouseButton.button;
    int x = wind_struct->event.mouseButton.x;
    int y = wind_struct->event.mouseButton.y;
    for (int c = st; struc[c] != NULL; c++) {
        if (x >= struc[c]->vect.x &&
            x <= struc[c]->vect.x + struc[c]->rect.width &&
            y >= struc[c]->vect.y &&
            y <= struc[c]->vect.y + struc[c]->rect.height) {
            c = k == 1 ? c * -1 : c;
            return c;
        }
    }
    return LOOP;
}

int choose(wdw *wind_struct, dsply **menu_sp, game *games)
{
    int x = event2(wind_struct, menu_sp, 2, 2);
    switch (x) {
        case 2:
            return play(wind_struct, games);
        case 3:
            return save_and_load(games, wind_struct, 0);
        case 4:
            settings(wind_struct);
            break;
        case 5:
            return EXIT_FUNC;
        case 6:
            manual(wind_struct);
            break;
    }
    return LOOP;
}

void anime_font(wdw *wind_struct, dsply **intro)
{
    if (wind_struct->second > 0.1) {
        intro[0]->rect.left += 1080;
        if (intro[0]->rect.left == 10800) {
            intro[0]->rect.left = 0;
            intro[0]->rect.top += 720;
        }
        if (intro[0]->rect.left >= 5400 && intro[0]->rect.top >= 2880)
            intro[0]->rect = (sfIntRect){0, 0, 1080, 720};
        sfClock_restart(wind_struct->clock);
    }
}

int menu(wdw *wind_struct, game *games)
{
    dsply **menu_sp = send_creat_menu();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        sfSprite_setScale(menu_sp[1]->sp, (sfVector2f){2, 2});
        display_sprite(menu_sp, wind_struct, 1);
        int d = choose(wind_struct, menu_sp, games);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        anime_font(wind_struct, menu_sp);
        if (d != LOOP) {
            destroy_sprite(menu_sp);
            free_double(menu_sp);
            return d;
        }
    }
    destroy_sprite(menu_sp);
    free_double(menu_sp);
    return EXIT_FUNC;
}
