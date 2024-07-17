/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** enemy_spawn
*/
#include "../my_rpg.h"
#include <time.h>

void init_enemie_sprite(rpg_t *rpg)
{
    sfRectangleShape *zone = sfRectangleShape_create();

    sfRectangleShape_setPosition(zone, (sfVector2f){1820, 480});
    rpg->enemies->enemies = sprite_create("assets/enemies/Orc.png");
    rpg->enemies->orc_rect = (sfIntRect){0, 0, 100, 100};
    sfSprite_setPosition(rpg->enemies->enemies, (sfVector2f){1820, 480});
}
