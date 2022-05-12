/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

void write_infl(char *buffer, int fl)
{
    write(fl, buffer, my_strlen(buffer, 127));
    free(buffer);
}

void save_player(wdw *wind_struct, game *games, char *path)
{
    int x = games->game[1]->vect.x;
    int y = games->game[1]->vect.y;
    int t = games->game[0]->rect.top;
    int l = games->game[0]->rect.left;
    int d = wind_struct->done_tuto;
    int p_y = wind_struct->pos_y;
    int p_x = wind_struct->pos_x;
    int sv_m = games->sv_map;
    int b_a = games->ba_save;
    int mny = wind_struct->money;
    int c_x = games->charizard[0]->vect.x;
    int c_y = games->charizard[0]->vect.y;
    char *p = my_conc("./save/player", path, 127);
    int z = open(p,
    O_CREAT | O_WRONLY | O_TRUNC, 0644);
    char *buff = my_concate_b("P!%d,%d:%d,%d:%d,%d:%d,%d:%d,%d:%d,%d:%d,%d:"
    "%d,%d:%d,0", y, x, t, l, games->t, games->l, d,games->player,
    p_y, p_x, sv_m, b_a, games->value, mny, c_y, c_x, games->beat_arceus);
    write_infl(buff, z);
    free(p);
}

void save_inventory(wdw *wind_struct, game *games, char *path)
{
    int *i = games->inventorys;
    int **p = games->poke_inventory;
    char *k = my_conc("./save/inventory", path, 127);
    int z = open(k,
    O_CREAT | O_WRONLY | O_TRUNC, 0644);
    char *buff = my_concate_b("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,"
    "%d,%d,%d,%d,%d,%d\n%d,%d,%d:%d,%d,%d:%d,%d,%d:%d,%d,%d:%d,%d,%d", i[0],
    i[1], i[2], i[3], i[4], i[5], i[6], i[7], i[8], i[9], i[10], i[11], i[12],
    i[13], i[14], i[15], i[16], i[17], i[18], p[0][0], p[0][1], p[0][2],
    p[1][0], p[1][1], p[1][2], p[2][0], p[2][1], p[2][2], p[3][0], p[3][1],
    p[3][2], p[4][0], p[4][1], p[4][2]);
    write_infl(buff, z);
    free(k);
}

int saves(wdw *wind_struct, game *games, char *path)
{
    save_player(wind_struct, games, path);
    save_inventory(wind_struct, games, path);
    free(path);
    return 1;
}