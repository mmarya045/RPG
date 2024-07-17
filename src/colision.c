/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** colision
*/

#include "../my_rpg.h"

sfBool colision(rpg_t *rpg, int dir)
{
    sfColor color;
    long int pos_x;
    long int pos_y;
    int vec = 20;
    sfVector2f d[4] = {{0, -vec}, {-vec, 0}, {0, vec}, {vec, 0}};

    rpg->player->player_pos = sfSprite_getPosition(rpg->player->player_sp);
    pos_x = (long int)rpg->player->player_pos.x;
    pos_y = (long int)rpg->player->player_pos.y;
    color = sfImage_getPixel(rpg->masque, pos_x + d[dir].x, pos_y + d[dir].y);
    return (color.r == 0 && color.b == 0 && color.g == 0 && color.a == 255);
}
