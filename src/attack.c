/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** attack
*/

#include "../my_rpg.h"

void attack_up(rpg_t *rpg)
{
    sfVector2f position;

    rpg->player->is_attacking = sfTrue;
    position = sfSprite_getPosition(rpg->player->player_sp);
    position.x -= 3;
    position.y += 25;
    sfSprite_setPosition(rpg->player->player_attack_sp, position);
    rpg->player->rect_attack.top = 96;
    rpg->player->last_direction = 96;
    rpg->player->rect_attack.left = 0;
    rpg->player->rect_basic.top = 999;
}

void attack_down(rpg_t *rpg)
{
    sfVector2f position;

    rpg->player->is_attacking = sfTrue;
    position = sfSprite_getPosition(rpg->player->player_sp);
    position.x -= 3;
    position.y += 25;
    sfSprite_setPosition(rpg->player->player_attack_sp, position);
    rpg->player->rect_attack.top = 0;
    rpg->player->last_direction = 0;
    rpg->player->rect_attack.left = 0;
    rpg->player->rect_basic.top = 999;
}

void attack_right(rpg_t *rpg)
{
    sfVector2f position;

    rpg->player->is_attacking = sfTrue;
    position = sfSprite_getPosition(rpg->player->player_sp);
    position.x -= 3;
    position.y += 25;
    sfSprite_setPosition(rpg->player->player_attack_sp, position);
    rpg->player->rect_attack.top = 48;
    rpg->player->last_direction = 48;
    rpg->player->rect_attack.left = 0;
    rpg->player->rect_basic.top = 999;
}

void attack_left(rpg_t *rpg)
{
    sfVector2f position;

    rpg->player->is_attacking = sfTrue;
    position = sfSprite_getPosition(rpg->player->player_sp);
    position.x -= 10;
    position.y += 35;
    sfSprite_setPosition(rpg->player->player_attack_sp, position);
    rpg->player->rect_attack.top = 240;
    rpg->player->last_direction = 336;
    rpg->player->rect_attack.left = 0;
    rpg->player->rect_basic.top = 999;
}

void handle_attack(rpg_t *rpg)
{
    if (rpg->player->is_attacking == sfTrue)
        return;
    if (rpg->player->look_up && rpg->event.mouseButton.button == sfMouseLeft)
        attack_up(rpg);
    if (rpg->player->look_down && rpg->event.mouseButton.button == sfMouseLeft)
        attack_down(rpg);
    if (rpg->player->look_right &&
    rpg->event.mouseButton.button == sfMouseLeft)
        attack_right(rpg);
    if (rpg->player->look_left && rpg->event.mouseButton.button == sfMouseLeft)
        attack_left(rpg);
}
