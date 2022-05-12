/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** create_fight.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **dsply_poke(game *games, int poke_at)
{
    int poke_u = get_place(games->poke_inventory[0][0],
    games->poke_inventory[0][1]);

    dsply **save = malloc(sizeof(*save) * 3);
    save[0] = create_object(get_poke_bck[poke_u].sprite_b,
    (sfVector2f){161, 284}, get_poke_bck[poke_u].rectb);
    save[1] = create_object(get_poke[poke_at].sprite_o,
    (sfVector2f){690, 90}, get_poke[poke_at].rect);
    save[2] = NULL;
    return save;
}

dsply **send_create_fight(void)
{
    dsply **save = malloc(sizeof(*save) * 8);
    save[0] = create_object("ressources/fight/fight_zone.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 240, 112});
    save[1] = create_object("ressources/fight/cho.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[2] = create_object("ressources/fight/cho_1.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[3] = create_object("ressources/fight/cho_2.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[4] = create_object("ressources/fight/cho_3.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[5] = create_object("ressources/fight/v.png",
    (sfVector2f){0, 161}, (sfIntRect){0, 0, 300, 104});
    save[6] = create_object("ressources/fight/vi.png",
    (sfVector2f){780, 0}, (sfIntRect){0, 0, 300, 85});
    save[7] = NULL;
    return save;
}

dsply **send_create_main_fight(void)
{
    dsply **save = malloc(sizeof(*save) * 8);
    save[0] = create_object("ressources/fight/fight_zone.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 240, 112});
    save[1] = create_object("ressources/fight/attack_1.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[2] = create_object("ressources/fight/attack_2.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[3] = create_object("ressources/fight/attack_3.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[4] = create_object("ressources/fight/attack_4.png",
    (sfVector2f){0, 461}, (sfIntRect){0, 0, 1080, 258});
    save[5] = create_object("ressources/fight/v.png",
    (sfVector2f){0, 161}, (sfIntRect){0, 0, 300, 104});
    save[6] = create_object("ressources/fight/vi.png",
    (sfVector2f){780, 0}, (sfIntRect){0, 0, 300, 85});
    save[7] = NULL;
    return save;
}

text **fight_text(game *games)
{
    int i = get_place(games->poke_inventory[0][0], games->poke_inventory[0][1]);
    text **save = malloc(sizeof(*save) * 9);
    save[0] = create_text(get_level(games->poke_inventory[0][1],
    games->poke_inventory[0][0]), (sfVector2f){270, 165}, 35, sfBlack);
    save[1] = create_text(get_level(0, games->poke_att),
    (sfVector2f){1050, 1}, 35, sfBlack);
    save[2] = create_text(get_poke[i].name,
    (sfVector2f){15, 155}, 40, sfBlack);
    save[3] = create_text(get_poke[games->poke_att].name,
    (sfVector2f){805, -5}, 40, sfBlack);
    save[4] = create_text(my_intchar(games->poke_inventory[0][2]),
    (sfVector2f){130, 200}, 30, sfWhite);
    save[5] = create_text(my_intchar(games->poke_life),
    (sfVector2f){920, 36}, 30, sfWhite);
    save[6] = create_text(get_poke[games->poke_att].name,
    (sfVector2f){60, 510}, 60, sfBlack);
    save[7] = create_text("has appeared",
    (sfVector2f){55, 580}, 60, sfBlack);
    save[8] = NULL;
    return save;
}

text **send_attack_temp(char **pok_1, game *games, int z)
{
    text **save = malloc(sizeof(*save) * 15);
    char **type = my_split(games->pok_1[z], ".", 0);
    save[0] = create_text(pok_1[5], (sfVector2f){101, 500}, 60, sfBlack);
    save[1] = create_text(pok_1[6], (sfVector2f){415, 500}, 60, sfBlack);
    save[2] = create_text(pok_1[7], (sfVector2f){101, 595}, 60, sfBlack);
    save[3] = create_text(pok_1[8], (sfVector2f){415, 595}, 60, sfBlack);
    save[4] = create_text("TYPE /", (sfVector2f){745, 490}, 60, sfBlack);
    save[5] = create_text("DAM /", (sfVector2f){755, 590}, 60, sfBlack);
    save[6] = type_of_attack(games, 0, save[6], (sfVector2f){875, 502});
    save[7] = type_of_attack(games, 1, save[7], (sfVector2f){860, 602});
    save[8] = create_text(get_level(games->poke_inventory[0][1],
    games->poke_inventory[0][0]), (sfVector2f){270, 165}, 35, sfBlack);
    save[9] = create_text(get_level(0, games->poke_att),
    (sfVector2f){1050, 1}, 35, sfBlack);
    return send_attack_temp_2(save, pok_1, games, z);
}