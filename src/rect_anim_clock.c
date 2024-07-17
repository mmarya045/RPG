/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** rext_anim_clock
*/

#include "../my_rpg.h"

void rect_animation_clock(rpg_t *rpg)
{
    rpg->time = sfClock_getElapsedTime(rpg->clock);
    rpg->seconds = rpg->time.microseconds / 1000000.0;
    if (rpg->seconds > 0.1) {
        if (rpg->player->rect_basic.top == 999
            && rpg->player->rect_attack.left >= 144) {
            rpg->player->rect_basic.top = rpg->player->last_direction;
            rpg->player->rect_attack.top = 999;
        }
        move_rect(&rpg->player->rect_basic, 48, 288);
        move_rect(&rpg->player->rect_attack, 48, 192);
        move_rect(&rpg->npc->npc_idle_rect, 37, 333);
        move_rect(&rpg->enemies->orc_rect, 100, 600);
        sfClock_restart(rpg->clock);
    }
}
