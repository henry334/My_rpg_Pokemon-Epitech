/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

text *create_text_sec(char *string, sfVector2f pos, int size, sfColor color)
{
    text *obj = malloc(sizeof(*obj));
    sfFont *font = sfFont_createFromFile("./ressources/ttf/arial.ttf");
    sfText *tst = sfText_create();
    sfText_setString(tst, string);
    sfText_setFont(tst, font);
    sfText_setCharacterSize(tst, size);
    sfText_setColor(tst, color);
    sfText_setPosition(tst, pos);
    obj->f = font;
    obj->txt = tst;
    return obj;
}

text *create_text(char *string, sfVector2f pos, int size, sfColor color)
{
    text *obj = malloc(sizeof(*obj));
    sfFont *font = sfFont_createFromFile("./ressources/ttf/pok.ttf");
    sfText *tst = sfText_create();
    sfText_setString(tst, string);
    sfText_setFont(tst, font);
    sfText_setCharacterSize(tst, size);
    sfText_setColor(tst, color);
    sfText_setPosition(tst, pos);
    obj->txt = tst;
    obj->f = font;
    return obj;
}

text **creat_text_setting_key(wdw *wind_struct)
{
    text **ttt = malloc(sizeof(*ttt) * 7);
    ttt[0] = create_text(nmm(wind_struct->key_left1),
    (sfVector2f){350, 315}, 55, sfWhite);
    ttt[1] = create_text(nmm(wind_struct->key_right1),
    (sfVector2f){350, 390}, 55, sfWhite);
    ttt[2] = create_text(nmm(wind_struct->key_up1),
    (sfVector2f){350, 455}, 55, sfWhite);
    ttt[3] = create_text(nmm(wind_struct->key_down1),
    (sfVector2f){350, 518}, 55, sfWhite);
    ttt[4] = create_text(nmm(wind_struct->key_inventory),
    (sfVector2f){350, 584}, 55, sfWhite);
    ttt[5] = create_text(nmm(wind_struct->key_poked),
    (sfVector2f){350, 646}, 55, sfWhite);
    ttt[6] = NULL;
    return ttt;
}

text **creat_money(char *s)
{
    text **money = malloc(sizeof(*money) * 3);
    money[0] = create_text_sec("$:", (sfVector2f){0, 0}, 45, sfWhite);
    money[1] = create_text_sec(s, (sfVector2f){62, 0}, 40, sfWhite);
    money[2] = NULL;
    free(s);
    return money;
}

text **creat_dlg(int x)
{
    int l;
    char *p = get_dg[x].path;
    char *dlg = readfile(my_conc("./ressources/dialogue/", p, 127));
    char **dialog = my_split(dlg, "\n", -1);
    text **dlgs = malloc(sizeof(*dlgs) * get_dg[x].size);
    for (l = 0; dialog[l] != NULL; l++) {
        dlgs[l] = create_text(dialog[l],
        (sfVector2f){110, 605}, 35, sfBlack);
    }
    dlgs[l] = NULL;
    free(dlg);
    free_double_char(dialog);
    return dlgs;
}
