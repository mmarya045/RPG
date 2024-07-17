/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** sprite_create
*/

#include "../my_rpg.h"

sfSprite *sprite_create(char *file)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfVector2f scale = {(float)2.0, (float)2.0};
    sfSprite *sprite = sfSprite_create();

    sfSprite_setScale(sprite, scale);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}
