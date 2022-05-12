/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** attack.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

char **att_pok_1(int id_1)
{
    char *attack_simp = readfile("./ressources/attack.txt");
    if (my_strcomp(attack_simp, "error") == 1)
        return my_split("ERRO", "\n", 0);
    char **attack = my_split(attack_simp, "\n", 0);
    if (my_twod_size(attack) != 12)
        return my_split("ERRO", "\n", 0);
    char *pok_1_simp = my_strdup(attack[id_1 + 1]);
    char **pok_1 = my_split(pok_1_simp, ";", 0);
    if (my_twod_size(pok_1) != 9)
        return my_split("ERRO", "\n", 0);

    free(attack_simp);
    free_double_char(attack);
    free(pok_1_simp);
    return pok_1;
}

int fight_speed_2(game *games, char **pok_2, wdw *wind_struct)
{
    int i = get_place(games->poke_inventory[0][0], games->poke_inventory[0][1]);
    games->damage_2 = make_damage_on_us(games, pok_2);
    games->damage_2 = games->damage_2 - (get_poke[i].defense / 2);
    games->poke_inventory[0][2] -= games->damage_2;
    games->poke_inventory[0][2] =
    games->poke_inventory[0][2] < 0 ? 0 : games->poke_inventory[0][2];
    update_life(games, wind_struct, games->attack, 1);
    display_prtcl(wind_struct, games->type_att, (sfVector2f){180, 460});
    return 0;
}

int fight_speed_1(game *games, char **pok_1, wdw *wind_struct)
{
    int z = games->z;
    games->damage = make_damage(games, pok_1, z);
    games->damage = games->damage - (get_poke[games->poke_att].defense / 2);
    games->poke_life -= games->damage;
    games->poke_life = games->poke_life < 0 ? 0 : games->poke_life;
    update_life(games, wind_struct, games->attack, 1);
    display_prtcl(wind_struct, games->type_you, (sfVector2f){740, 270});
    return 0;
}
