/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **quest_valide(void)
{
    dsply **intro = malloc(sizeof(*intro) * 3);
    intro[0] = create_object("./ressources/sprite/menu_sprite/cross.png",
    (sfVector2f){1000, 13}, (sfIntRect){0, 0, 55, 55});
    intro[1] = create_object("./ressources/sprite/menu_sprite/green.png",
    (sfVector2f){1000, 13}, (sfIntRect){0, 0, 55, 47});
    intro[2] = NULL;
    return intro;
}

text **create_quest(void)
{
    text **quest = malloc(sizeof(*quest) * 2);
    quest[0] = create_text("Beat arceus:", (sfVector2f){740, -2}, 60, sfWhite);
    quest[1] = NULL;
    return quest;
}

void display_quest(game *games, wdw *wind_struct)
{
    if (games->in_combat == 0) {
        display_text(games->quest, wind_struct);
        sfRenderWindow_drawSprite(wind_struct->window,
        games->vld_quest[games->beat_arceus]->sp, NULL);
    }
    return;
}