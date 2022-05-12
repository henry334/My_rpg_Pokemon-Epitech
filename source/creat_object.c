/*
** EPITECH PROJECT, 2022
** epitech
** File description:
** code.c
*/

#include "../includes/rpg.h"
#include "../includes/print.h"

dsply *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect)
{
    dsply *obj = malloc(sizeof(*obj));
    sfTexture *texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    sfSprite *sprite = sfSprite_create();
    obj->txtu = texture;
    obj->rect = rect;
    obj->sp = sprite;
    obj->vect = pos;
    sfSprite_setPosition(obj->sp, obj->vect);
    sfSprite_setTexture(obj->sp, obj->txtu, sfTrue);
    sfSprite_setTextureRect(obj->sp, obj->rect);
    return obj;
}

dsply **send_creat_menu(void)
{
    dsply **save = malloc(sizeof(*save) * 8);
    save[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    save[1] = create_object("./ressources/sprite/menu_sprite/arceus.png",
    (sfVector2f){470, 10}, (sfIntRect){0, 0, 262, 345});
    save[2] = create_object("./ressources/sprite/menu_sprite/New_Btn.png",
    (sfVector2f){50, 120}, (sfIntRect){0, 0, 240, 80});
    save[3] = create_object("./ressources/sprite/menu_sprite/Load_Btn.png",
    (sfVector2f){50, 250}, (sfIntRect){0, 0, 240, 80});
    save[4] = create_object("./ressources/sprite/menu_sprite/Settings_Btn.png",
    (sfVector2f){50, 380}, (sfIntRect){0, 0, 240, 80});
    save[5] = create_object("./ressources/sprite/menu_sprite/Exit_Button.png",
    (sfVector2f){50, 510}, (sfIntRect){0, 0, 240, 80});
    save[6] = create_object("./ressources/sprite/menu_sprite/Questionmark.png",
    (sfVector2f){1010, 650}, (sfIntRect){0, 0, 70, 70});
    save[7] = NULL;
    return save;
}

dsply **creat_setting(void)
{
    dsply **setting = malloc(sizeof(*setting) * 14);
    setting[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    setting[1] = create_object("./ressources/sprite/menu_sprite/Back_Btn.png",
    (sfVector2f){0, 650}, (sfIntRect){0, 0, 70, 70});
    setting[2] = create_object("./ressources/sprite/menu_sprite/Audio_Btn.png",
    (sfVector2f){1009, 2}, (sfIntRect){0, 0, 70, 70});
    setting[3] = create_object("./ressources/sprite/menu_sprite/30.png",
    (sfVector2f){230, 180}, (sfIntRect){0, 0, 85, 85});
    setting[4] = create_object("./ressources/sprite/menu_sprite/60.png",
    (sfVector2f){350, 180}, (sfIntRect){0, 0, 85, 85});
    setting[5] = create_object("./ressources/sprite/menu_sprite/120.png",
    (sfVector2f){470, 180}, (sfIntRect){0, 0, 85, 85});
    setting[6] = create_object("./ressources/sprite/menu_sprite/fps.png",
    (sfVector2f){90, 180}, (sfIntRect){0, 0, 85, 85});
    return creat_setting_two(setting);
}

dsply **send_manual(void)
{
    dsply **intro = malloc(sizeof(*intro) * 2);
    intro[0] = create_object("./ressources/intro/pokemon_arceus_manual.png",
    (sfVector2f){0, 0}, (sfIntRect){165, 0, 1080, 720});
    intro[1] = NULL;
    return intro;
}

dsply **send_intro(void)
{
    dsply **intro = malloc(sizeof(*intro) * 4);
    intro[0] = create_object("./ressources/intro/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    intro[1] = create_object("./ressources/intro/press_key.png",
    (sfVector2f){290, 600}, (sfIntRect){0, 0, 535, 51});
    intro[2] = create_object("./ressources/intro/logo.png",
    (sfVector2f){245, 0}, (sfIntRect){0, 0, 1200, 942});
    intro[3] = NULL;
    return intro;
}