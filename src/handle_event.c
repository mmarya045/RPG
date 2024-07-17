/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** handle_event
*/

#include "../my_rpg.h"

void set_texture_rect(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->npc->npc_idle, rpg->npc->npc_idle_rect);
    sfSprite_setTextureRect(rpg->npc->npc_jump, rpg->npc->npc_jump_rect);
    sfSprite_setTextureRect(rpg->player->player_sp, rpg->player->rect_basic);
    sfSprite_setTextureRect(rpg->enemies->enemies, rpg->enemies->orc_rect);
}

void player_global(rpg_t *rpg)
{
    sfView_setCenter(rpg->view, rpg->player->player_pos);
    handle_in_game_inv(rpg);
    basic_movement(rpg);
    handle_attack(rpg);
}

void handle_resolution(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtKeyPressed) {
            rpg->window = resolution(rpg->window, rpg->event);
    }
}

void handle_event(rpg_t *rpg)
{
    const sfFloatRect player_hitbox =
    sfSprite_getGlobalBounds(rpg->player->player_sp);
    const sfFloatRect npc_hitbox =
    sfSprite_getGlobalBounds(rpg->npc->npc_idle);
    const sfFloatRect enemie_hitbox =
    sfSprite_getGlobalBounds(rpg->enemies->enemies);

    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        handle_close_window(rpg->event, rpg->window);
        player_global(rpg);
        handle_resolution(rpg);
        handle_collision_pnj(player_hitbox, npc_hitbox, rpg);
        handle_collision_enemie(player_hitbox, enemie_hitbox, rpg);
    }
    set_texture_rect(rpg);
}
