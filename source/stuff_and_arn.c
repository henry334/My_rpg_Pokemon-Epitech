/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void update_life(game *games, wdw *wind_struct, text **attack, int mode)
{
    char *temp = my_intchar(games->poke_inventory[0][2]);
    char *temmp = my_intchar(games->poke_life);
    int i = get_place(games->poke_inventory[0][0], games->poke_inventory[0][1]);
    if (mode == 1) {
        sfText_setString(attack[12]->txt, temp);
        sfText_setString(attack[13]->txt, temmp);
    } else {
        display_text(attack, wind_struct);
        sfText_setString(attack[2]->txt, get_poke[i].name);
        sfText_setString(attack[4]->txt, temp);
        sfText_setString(attack[5]->txt, temmp);
    }
    free(temp);
    free(temmp);
}

char *get_level(int xp, int num)
{
    if (xp < 300 && num < 5)
        return "1";
    return "2";
}

void manager_charizard(game *games, int mode, int y, int x)
{
    float yy = y;
    float xx = x;

    if (y != 0 && mode == 0) {
        yy += yy >= 0 ? 4.8 : -4.8;
        games->charizard[0]->vect.y += yy * -1;
    }
    if (x != 0 && mode == 1) {
        xx += xx >= 0 ? 4.8 : -4.8;
        games->charizard[0]->vect.x += xx * -1;
    }
}

void music_fight(wdw *wind_struct , int mode)
{
    if (mode == 0 && wind_struct->music_on_off == 0) {
        sfMusic_stop(wind_struct->music);
        sfMusic_play(wind_struct->msc_cm);
        sfMusic_setLoop(wind_struct->msc_cm, sfTrue);
    }
    if (mode == 1 && wind_struct->music_on_off == 0) {
        sfMusic_play(wind_struct->music);
        sfMusic_stop(wind_struct->msc_cm);
    }
}

void arene(game *games, wdw *wind_struct)
{
    int x = random_poke(5) + 5;
    games->in_combat = 1;
    games->poke_att = x;
    games->poke_life = get_poke[x].life;
    intro_fight(wind_struct, games, x);
    sfMusic_stop(wind_struct->msc_cm);
}