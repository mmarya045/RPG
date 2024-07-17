/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_sprite_permutation
*/

#include "../my_rpg.h"

void handle_sprite_permutation(rpg_t *rpg)
{
    if (rpg->player->rect_basic.top != 999)
            rpg->player->rect_attack.top = 999;
    if (rpg->player->rect_attack.left >= 144)
            rpg->player->is_attacking = sfFalse;
    sfSprite_setTextureRect(rpg->player->player_attack_sp,
    rpg->player->rect_attack);
}
