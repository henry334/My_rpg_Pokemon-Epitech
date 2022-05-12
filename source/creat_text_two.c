/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

text **creat_num(char *s)
{
    text **money = malloc(sizeof(*money) * 3);
    money[0] = create_text(s, (sfVector2f){540, 217}, 70, sfWhite);
    money[1] = create_text("Choose your save",
    (sfVector2f){370, 50}, 70, sfWhite);
    money[2] = NULL;
    return money;
}

text **creat_end_tuto(void)
{
    text **save = malloc(sizeof(save) * 2);
    save[0] = create_text(
    "(A) Pikachu\t (B) Salameche\n(C) Roucoule\t (D) Fantominus\t (E) Griknot",
    (sfVector2f){128, 550}, 65, sfBlack);
    save[1] = NULL;
    return save;
}

text **creat_poke_text(game *games)
{
    int n = 1;
    int y = 132;
    int s = num_of_pokemon(games);

    text **money = malloc(sizeof(*money) * (s + 3));
    money[0] = create_text("Your Pokemon", (sfVector2f){385, 25}, 75, sfWhite);
    for (int c = 0; games->poke_inventory[c] != NULL &&
        games->poke_inventory[c][0] != -1; c++) {
        int p = get_place(games->poke_inventory[c][0],
        games->poke_inventory[c][1]);
        char *buff = my_concate_b("Xp: %d  Life: %d\nSpeed: %d  Attack: %d",
        games->poke_inventory[c][1], games->poke_inventory[c][2],
        get_poke[p].speed, get_poke[p].attack);
        money[n] = create_text(buff, (sfVector2f) {390, y}, 40, sfWhite);
        y += 90;
        n++;
        free(buff);
    }
    money[n] = NULL;
    return money;
}

text **send_attack_temp_2(text **save, char **pok_1, game *games, int z)
{
    save[10] = create_text(get_poke[games->poke_inventory[0][0]].name,
    (sfVector2f){15, 155}, 40, sfBlack);
    save[11] = create_text(get_poke[games->poke_att].name,
    (sfVector2f){805, -5}, 40, sfBlack);
    save[12] = create_text(my_intchar(games->poke_inventory[0][2]),
    (sfVector2f){130, 200}, 30, sfWhite);
    save[13] = create_text(my_intchar(games->poke_life),
    (sfVector2f){920, 36}, 30, sfWhite);
    save[14] = NULL;
    return save;
}

dsply **send_create_intro_fight(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("ressources/fight/intro_fight.png",
    (sfVector2f){1080, 0}, (sfIntRect){0, 0, 1080, 720});
    save[1] = NULL;
    return save;
}
