/*
** EPITECH PROJECT, 2024
** tmp
** File description:
** test
*/

#include "../my_rpg.h"

int play(void)
{
    rpg_t *rpg = init_struct();
    sfMusic *son = sfMusic_createFromFile("assets/alphatron.wav");

    sfMusic_setVolume(son, 50);
    sfMusic_setLoop(son, sfTrue);
    sfMusic_play(son);
    while (sfRenderWindow_isOpen(rpg->window)) {
        handle_sprite_permutation(rpg);
        rpg->player->player_pos = sfSprite_getPosition(rpg->player->player_sp);
        handle_event(rpg);
        rect_animation_clock(rpg);
        handle_window(rpg);
    }
    sfRenderWindow_destroy(rpg->window);
    sfSprite_destroy(rpg->player->player_sp);
    sfSprite_destroy(rpg->player->player_attack_sp);
    sfSprite_destroy(rpg->background);
    free(rpg->player);
    free(rpg);
}
