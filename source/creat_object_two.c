/*
** EPITECH PROJECT, 2021
** epitech
** File description:
** the_code
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply **send_creat_play(void)
{
    dsply **save = malloc(sizeof(*save) * 5);
    save[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    save[1] = create_object("./ressources/char/pres/boy_big.png",
    (sfVector2f){200, 250}, (sfIntRect){0, 0, 300, 300});
    save[2] = create_object("./ressources/char/pres/girl_big.png",
    (sfVector2f){575, 250}, (sfIntRect){0, 0, 300, 300});
    save[3] = create_object("./ressources/sprite/menu_sprite/Back_Btn.png",
    (sfVector2f){0, 650}, (sfIntRect){0, 0, 70, 70});
    save[4] = NULL;
    return save;
}

dsply **creat_setting_two(dsply **making)
{
    making[7] = create_object("./ressources/sprite/menu_sprite/unnamed(1).png",
    (sfVector2f){92, 310}, (sfIntRect){0, 0, 220, 73});
    making[8] = create_object("./ressources/sprite/menu_sprite/unnamed(2).png",
    (sfVector2f){92, 380}, (sfIntRect){0, 0, 220, 73});
    making[9] = create_object("./ressources/sprite/menu_sprite/unnamed(3).png",
    (sfVector2f){92, 450}, (sfIntRect){0, 0, 220, 73});
    making[10] = create_object
    ("./ressources/sprite/menu_sprite/unnamed(4).png",
    (sfVector2f){92, 515}, (sfIntRect){0, 0, 220, 73});
    making[11] = create_object
    ("./ressources/sprite/menu_sprite/unnamed(5).png",
    (sfVector2f){92, 580}, (sfIntRect){0, 0, 220, 73});
    making[12] = create_object
    ("./ressources/sprite/menu_sprite/unnamed(6).png",
    (sfVector2f){92, 645}, (sfIntRect){0, 0, 220, 73});
    making[13] = NULL;
    return making;
}

dsply **send_creat_game(char *player, int c)
{
    int co = get_chars[c].pe;
    dsply **save = malloc(sizeof(*save) * 4);
    save[0] = create_object(get_bck[c].path,
    get_bck[c].pos, get_bck[c].rect);
    save[1] = create_object(player,
    get_perso[co].v_pe, (sfIntRect){13, 14, 64, 59});
    sfSprite_scale(save[0]->sp, get_bck[c].scl);
    save[2] = NULL;
    return save;
}

dsply **send_creat_inventory(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/inventory/inventory.png",
    (sfVector2f){300, 230}, (sfIntRect){60, 120, 480, 260});
    save[1] = NULL;
    return save;
}

dsply **creat_text(void)
{
    dsply **save = malloc(sizeof(*save) * 2);
    save[0] = create_object("./ressources/dialogue/dlg.png",
    (sfVector2f){0, 545}, (sfIntRect){0, 0, 1080, 170});
    save[1] = NULL;
    return save;
}