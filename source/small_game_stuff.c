/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void check_interaction(game *games, wdw *wind_struct)
{
    display_sprite(games->game, wind_struct, 1);
    games->is_speaking == 9 ?
    shop(wind_struct, games) : games->is_speaking;
    games->is_speaking == 8 ?
    pharmacy(games, wind_struct) : games->is_speaking;
    games->is_speaking == 7 ?
    arene(games, wind_struct) : games->is_speaking;
    games->is_speaking == 6 && games->beat_arceus == 0 ?
    arceus_fight(games, wind_struct) : games->is_speaking;
    games->is_speaking < 6 ?
    conv(wind_struct, games->is_speaking) : games->is_speaking;
}

int get_start(game *games)
{
    int i = get_place(games->poke_inventory[0][0], games->poke_inventory[0][1]);
    if (get_poke[games->poke_att].speed > get_poke[i].speed)
        return 0;
    if (get_poke[games->poke_att].speed == get_poke[i].speed)
        return random_poke(2);
    if (get_poke[i].speed > get_poke[games->poke_att].speed)
        return 1;
    return 0;
}

void scale_fight(wdw *wind_struct, dsply **poke, dsply **fight)
{
    sfSprite_setScale(fight[0]->sp, (sfVector2f){4.52, 4.15});
    sfVector2f pok_size = {2.6875, 2.6875};
    sfSprite_setScale(poke[0]->sp, pok_size);
    sfSprite_setScale(poke[1]->sp, pok_size);
}

void reset_to(wdw *wind_struct)
{
    wind_struct->done_tuto = 0;
    wind_struct->ph = 0;
    wind_struct->which = -1;
    wind_struct->lock = 0;
    wind_struct->scene = 0;
    wind_struct->back_menu = 0;
    wind_struct->money = 500;
    wind_struct->s_l = 0;
    wind_struct->s_u = 0;
    wind_struct->s_r = 0;
    wind_struct->s_d = 0;
    wind_struct->pos_y = 366;
    wind_struct->pos_x = 529;
}

void display_prtcl(wdw *wind_struct, int type, sfVector2f p)
{
    sfTime time;
    float second = 0;
    framebuffer_t *fbuffer = framebuffer_create(1920, 1080);
    sfClock *clock = sfClock_create();
    for (int c = 0; second < 0.32; c++) {
        sfVector2u center = {p.x + random_poke(180), p.y - random_poke(130)};
        sfRenderWindow_display(wind_struct->window);
        time = sfClock_getElapsedTime(clock);
        second = time.microseconds / 1000000.0;
        circle_particle(fbuffer, center, 9, type);
        display_fbuffer(fbuffer, wind_struct->window);
    }
    free(fbuffer->pixels);
    free(fbuffer);
    sfClock_restart(clock);
    second = 0;
    for (int c = 0; second < 0.4; c++) {
        time = sfClock_getElapsedTime(clock);
        second = time.microseconds / 1000000.0;
    }
}