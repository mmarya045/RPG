/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** init_rect
*/

#include "../my_rpg.h"

sfIntRect init_rect(sfIntRect rect, int width, int height)
{
    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return rect;
}
