/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

int do_job(game *games, wdw *wind_struct, int z, int mode)
{
    char *temp = my_intchar(z);
    temp = my_conc(temp, ".txt", 127);
    if (mode == 0)
        return load(wind_struct, games, temp);
    if (mode == 1)
        return saves(wind_struct, games, temp);
}

dsply **create_load_p(void)
{
    dsply **intro = malloc(sizeof(*intro) * 6);
    intro[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    intro[1] = create_object("./ressources/sprite/menu_sprite/-.png",
    (sfVector2f){405, 220}, (sfIntRect){0, 0, 85, 85});
    intro[2] = create_object("./ressources/sprite/menu_sprite/+.png",
    (sfVector2f){605, 220}, (sfIntRect){0, 0, 85, 85});
    intro[3] = create_object("./ressources/sprite/menu_sprite/green2.png",
    (sfVector2f){510, 350}, (sfIntRect){0, 0, 85, 77});
    intro[4] = create_object("./ressources/sprite/menu_sprite/Back_Btn.png",
    (sfVector2f){0, 650}, (sfIntRect){0, 0, 70, 70});
    intro[5] = NULL;
    return intro;
}

int save_num(int x, int z)
{
    if (x == 2)
        z = z == 9 ? 0 : z + 1;
    else if (x == 1)
        z = z == 0 ? 9 : z - 1;
    return z;
}

int choosess(wdw *wind_struct, dsply **btn, int z)
{
    int x = event2(wind_struct, btn, 1, 2);
    switch (x) {
        case 1:
            return save_num(x, z);
        case 2:
            return save_num(x, z);
        case 3:
            return EXIT_FUNC;
        case 4:
            return -1;
        default:
            break;
    }
    return LOOP;
}

int save_and_load(game *games, wdw *wind_struct, int mode)
{
    int z = 0;
    int p = 0;
    dsply **load_sp = create_load_p();
    text **num = creat_num("0");
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(load_sp, wind_struct, 1);
        display_text(num, wind_struct);
        p = choosess(wind_struct, load_sp, z);
        if (p != LOOP && p != EXIT_FUNC && p != -1) {
            z = p;
            sfText_setString(num[0]->txt, my_intchar(z));
        } else if (p == EXIT_FUNC || p == -1)
            break;
    }
    destroy_load_save(load_sp, num);
    if (p == -1 || p == LOOP)
        return LOOP;
    return do_job(games, wind_struct, z, mode);
}