/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** background_create
*/

#include "../my_rpg.h"

sfSprite *background_create(char *file)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}

sfImage *map_masque_create(char *file)
{
    sfImage *image = sfImage_createFromFile(file);

    return image;
}
