/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int is_let(char s)
{
    if (s >= 48 && s <= 57)
        return 2;
    if (s >= 97 && s <= 122)
        return 1;
    if (s == 34)
        return 3;
    return 0;
}

void setup(int ba, int pe, game *games, wdw *wind_struct)
{
    char *s = readfile(get_bck[ba].map);
    wind_struct->map = my_split(s, "\n", -1);
    sfTexture_destroy(games->game[0]->txtu);
    sfSprite_destroy(games->game[0]->sp);
    games->game[0] = create_object(get_bck[ba].path,
    get_bck[ba].pos, get_bck[ba].rect);
    sfSprite_scale(games->game[0]->sp, get_bck[ba].scl);
    games->game[1]->vect = get_perso[pe].v_pe;
    games->max_l = get_bck[ba].ml;
    games->max_t = get_bck[ba].mt;
    games->l = 0;
    games->t = 0;
    wind_struct->pos_y = get_perso[pe].y;
    wind_struct->pos_x = get_perso[pe].x;
    wind_struct->s_l = 0;
    wind_struct->s_u = 0;
    wind_struct->s_r = 0;
    wind_struct->s_d = 0;
    change_rect(games, get_perso[pe].way);
    free(s);
}

void replace(wdw *wind_struct, game *game, char code)
{
    if (code == 'z') {
        game->sv_map = 0;
        int p = game->ba_save;
        free_double_char(wind_struct->map);
        setup(get_chars[p].out_ba,
        get_chars[p].out_pe, game, wind_struct);
        game->ba_save = -1;
    }
    for (int c = 0; get_chars[c].n != -1; c++) {
        if (code == get_chars[c].n) {
            game->sv_map = c;
            game->ba_save = game->ba_save == -1 ? c : game->ba_save;
            free_double_char(wind_struct->map);
            setup(get_chars[c].ba, get_chars[c].pe, game, wind_struct);
            game->t = code == 'k' ? 345 : game->t;
            game->l = code == 'k' ? -345 : game->l;
            game->t = code == 'p' ? -246 : game->t;
            game->l = code == 'p' ? -180 : game->l;
        }
    }
}

int check_other_col(wdw *wind_struct, int yy, int xx, game *games)
{
    char **map = wind_struct->map;
    int l = is_let(map[yy][xx]);

    if (l == 1) {
        replace(wind_struct, games, map[yy][xx]);
        return 1;
    }
    if (l == 2) {
        games->is_speaking = map[yy][xx] - '0';
        return 2;
    }
    games->is_speaking = -1;
    if (l == 3) {
        do_we_fight(games, wind_struct);
        return 3;
    }
    return 0;
}

int collision(wdw *wind_struct, game *game, int y, int x)
{
    int yy = wind_struct->pos_y + y;
    int xx = wind_struct->pos_x + x;
    int p = check_other_col(wind_struct, yy, xx, game);
    char **map = wind_struct->map;

    if (p != 1 && map[yy][xx] == ' ' || p == 2 || p == 3) {
        return 1;
    }
    return 0;
}