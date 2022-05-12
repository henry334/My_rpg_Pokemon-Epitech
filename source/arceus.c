/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void arceus_disp(game *games)
{
    if (games->second > 0.15 && games->arceus_disp == 0) {
        games->arceus_disp = 1;
        sfClock_restart(games->clock);
    } else if (games->second > 0.15 && games->arceus_disp == 1) {
        games->arceus_disp = 0;
        sfClock_restart(games->clock);
    }
}

dsply **create_arceus(void)
{
    dsply **save = malloc(sizeof(*save) * 3);
    save[0] = create_object("./ressources/char/mov/arceus.png",
    (sfVector2f){530, 195}, (sfIntRect){0, 0, 26, 40});
    save[1] = create_object("./ressources/char/mov/arceus1.png",
    (sfVector2f){530, 195}, (sfIntRect){0, 0, 26, 40});
    sfSprite_scale(save[0]->sp, (sfVector2f){1.90, 1.90});
    sfSprite_scale(save[1]->sp, (sfVector2f){1.90, 1.90});
    save[2] = NULL;
    return save;
}

void arceus_fight(game *games, wdw *wind_struct)
{
    int x = 10;
    int code;

    games->in_combat = 1;
    games->poke_att = x;
    games->poke_life = get_poke[x].life;
    code = intro_fight(wind_struct, games, x);

    if (code == 2)
        games->beat_arceus = 1;
    sfMusic_stop(wind_struct->msc_cm);
}