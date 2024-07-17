/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_player_sprite
*/

#include "../my_rpg.h"

void init_player_sprite(rpg_t *rpg)
{
    rpg->player->player_attack_sp = sprite_create("assets/player/attack.png");
    rpg->player->player_sp =
    sprite_create("assets/player/player_movement.png");
    rpg->player->rect_basic = (sfIntRect){0, 0, 48, 48};
    rpg->player->rect_attack = (sfIntRect){0, 96, 48, 48};
    rpg->player->look_down = sfTrue;
    sfSprite_setPosition(rpg->player->player_sp, (sfVector2f){1010, 580});
}
