/*
** EPITECH PROJECT, 2021
** B-MUL-200-PAR-2-3-myrpg-henry.giraud
** File description:
** type_of_attack.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

text *type_of_attack(game *games, int num, text *temp, sfVector2f pos)
{
    int z = games->z;
    char **type = my_split(games->pok_1[z], ".", 0);
    if (my_twod_size(type) != 2) {
        my_printf("CANT LOAD ATTACK PLS CHECK ATTACK FILE\n");
        temp = create_text("ERROR", pos, 50, sfBlack);
        return temp;
    }
    temp = create_text(type[num], pos, 50, sfBlack);
    free_double_char(type);
    return temp;
}

void damage(game *games, int num, int where)
{
    int z = games->z;
    char **type = my_split(games->pok_1[z], ".", 0);
    if (my_twod_size(type) != 2) {
        my_printf("CANT LOAD ATTACK PLS CHECK ATTACK FILE\n");
        sfText_setString(games->attack[where]->txt, "ERROR");
        return;
    }
    sfText_setString(games->attack[where]->txt, type[num]);
    free_double_char(type);
}

int get_type_pok(char *attack)
{
    for (int i = 0; i != 17; i++) {
        if (my_strcomp(get_type[i].type, attack) == 1)
            return get_type[i].id;
    }
    return 0;
}

double make_damage(game *games, char **pok_1, int z)
{
    int i = get_place(games->poke_inventory[0][0], games->poke_inventory[0][1]);
    char **attack = my_split(pok_1[z], ".", 0);
    if (my_twod_size(attack) != 2) {
        my_printf("CANT LOAD ATTACK PLS CHECK ATTACK FILE\n");
        return 0;
    }
    int type = get_type_pok(attack[0]);
    games->type_you = type;
    int damage = my_getnbr(attack[1]);
    double attack_stat = 0.01 * get_poke[i].attack;
    double total_damage = damage * attack_stat;
    free_double_char(attack);
    return total_damage;
}

double make_damage_on_us(game *games, char **pok_2)
{
    int nbr = random_poke(4);
    char **attack = my_split(pok_2[nbr + 1], ".", 0);
    if (my_twod_size(attack) != 2) {
        my_printf("CANT LOAD ATTACK PLS CHECK ATTACK FILE\n");
        return 0;
    }
    int type = get_type_pok(attack[0]);
    games->type_att = type;
    int damage = my_getnbr(attack[1]);
    double attack_stat = 0.01 * get_poke[games->poke_att].attack;
    double total_damage = damage * attack_stat;
    free_double_char(attack);
    return total_damage;
}