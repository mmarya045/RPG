/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_window_elem
*/

#include "../my_rpg.h"

void init_npc_sprite(rpg_t *rpg)
{
    rpg->npc->npc_idle = sprite_create("assets/npc/idle.png");
    rpg->npc->npc_jump = sprite_create("assets/npc/jump.png");
    rpg->npc->dialog = sprite_create("assets/npc/dialog.png");
    sfSprite_setScale(rpg->npc->dialog, (sfVector2f){1.2, 1.2});
    rpg->npc->npc_jump_rect = (sfIntRect){0, 0, 37, 32};
    rpg->npc->npc_idle_rect = (sfIntRect){0, 0, 37, 32};
    sfSprite_setPosition(rpg->npc->npc_idle, (sfVector2f){1010, 800});
}

void init_window_elem(rpg_t *rpg)
{
    rpg->window = create_window(1920, 1080);
    init_npc_sprite(rpg);
    init_enemie_sprite(rpg);
    init_player_sprite(rpg);
    rpg->background = background_create("assets/map.png");
    rpg->structure = background_create("assets/my_rpg3.png");
    rpg->masque = map_masque_create("./assets/map_masque.png");
    sfSprite_setOrigin(rpg->background, (sfVector2f){-40, -70});
    sfSprite_setOrigin(rpg->structure, (sfVector2f){-40, -70});
    init_sfview(rpg);
}
