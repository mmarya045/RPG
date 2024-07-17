/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_key
*/

#include "../my_rpg.h"

void handle_z_key(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyZ) {
        if (colision(rpg, 0)) {
            return;
        }
        set_all_bool_false(rpg);
        sfSprite_move(rpg->player->player_sp, (sfVector2f){0.0, -rpg->speed});
        rpg->player->rect_basic.top = 240;
        rpg->player->look_up = sfTrue;
    }
}

void handle_q_key(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyQ) {
        if (colision(rpg, 1))
            return;
        set_all_bool_false(rpg);
        sfSprite_move(rpg->player->player_sp, (sfVector2f){-rpg->speed, 00.0});
        rpg->player->rect_basic.top = 288;
        rpg->player->look_left = sfTrue;
    }
}

void handle_s_key(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyS) {
        if (colision(rpg, 2))
            return;
        set_all_bool_false(rpg);
        sfSprite_move(rpg->player->player_sp, (sfVector2f){0.0, rpg->speed});
        rpg->player->rect_basic.top = 144;
        rpg->player->look_down = sfTrue;
    }
}

void handle_d_key(rpg_t *rpg)
{
    if (rpg->event.key.code == sfKeyD) {
        if (colision(rpg, 3))
            return;
        set_all_bool_false(rpg);
        sfSprite_move(rpg->player->player_sp, (sfVector2f){rpg->speed, 0.0});
        rpg->player->rect_basic.top = 192;
        rpg->player->look_right = sfTrue;
    }
}

void basic_movement(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
        handle_z_key(rpg);
        handle_q_key(rpg);
        handle_s_key(rpg);
        handle_d_key(rpg);
    }
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyZ)
            rpg->player->rect_basic.top = 96;
        if (rpg->event.key.code == sfKeyQ)
            rpg->player->rect_basic.top = 336;
        if (rpg->event.key.code == sfKeyS)
            rpg->player->rect_basic.top = 0;
        if (rpg->event.key.code == sfKeyD)
            rpg->player->rect_basic.top = 48;
    }
}
