/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** fight.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int get_sprite(int z, int x)
{
    if (z + x <= 0 || z + x > 4 ||
    z == 2 && x == 1 || z == 3 && x == -1)
        z += x * -1;
    else
        z += x;
    return z;
}

int which_choose(wdw *wind_struct, game *games, dsply **fight)
{
    int x = event2(wind_struct, fight, 1, 3);
    if (x == wind_struct->key_up1)
        return -2;
    else if (x == wind_struct->key_right1)
        return 1;
    else if (x == wind_struct->key_down1)
        return 2;
    else if (x == wind_struct->key_left1)
        return -1;
    else if (x == 58)
        return 5;
    else
        return LOOP;
}

void display_fight(wdw * wind_struct, dsply **fight, dsply **poke, int z)
{
    sfRenderWindow_display(wind_struct->window);
    sfRenderWindow_clear(wind_struct->window, sfBlack);
    scale_fight(wind_struct, poke, fight);
    sfRenderWindow_drawSprite(wind_struct->window, fight[0]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, poke[0]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, poke[1]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, fight[5]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, fight[6]->sp, NULL);
    sfRenderWindow_drawSprite(wind_struct->window, fight[z]->sp, NULL);
}

int fight(wdw *wind_struct, game *games, int poke_at)
{
    int ex = 0;
    int z = 1;
    dsply **fight = send_create_fight();
    dsply **poke = dsply_poke(games, poke_at);
    text **text_1 = fight_text(games);
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_fight(wind_struct, fight, poke, z);
        update_life(games, wind_struct, text_1, 0);
        int x = which_choose(wind_struct, games, fight);
        if (x != LOOP && x != 5) {
            z = get_sprite(z, x);
        } else if (x == 5) {
            ex = inside(z, wind_struct, games, poke);
            poke = ex == 2 ? dsply_poke(games, poke_at) : poke;
        }
        if (ex == 4)
            break;
    }
    free_fight_f(poke, fight, text_1);
    return games->in_combat;
}

int intro_fight(wdw *wind_struct, game *games , int poke_at)
{
    music_fight(wind_struct, 0);
    dsply **intro_fight = send_create_intro_fight();
    while (intro_fight[0]->rect.left < 8520) {
        display_sprite(games->game, wind_struct, 1);
        display_sprite(intro_fight, wind_struct, 0);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        if (wind_struct->second > 0.01 && intro_fight[0]->vect.x <= 0) {
            intro_fight[0]->rect.left += 75;
            sfClock_restart(wind_struct->clock);
        } else if (wind_struct->second > 0.01) {
            intro_fight[0]->vect.x -= 60;
            sfClock_restart(wind_struct->clock);
        }
    }
    int x = fight(wind_struct, games, poke_at);
    music_fight(wind_struct, 1);
    destroy_sprite(intro_fight);
    games->in_combat = 0;
    return x;
}
