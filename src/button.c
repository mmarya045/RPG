/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** button
*/

#include "../my_rpg.h"

button_t *init_button(Vector_t pos, Vector_t sze, sfTexture *text, but_t *but)
{
    if (but == NULL) {
        but = malloc(sizeof(button_t));
        but->rect = sfRectangleShape_create();
    }
    sfRectangleShape_setPosition(but->rect, pos);
    sfRectangleShape_setSize(but->rect, sze);
    sfRectangleShape_setTexture(but->rect, text, sfTrue);
    but->is_clicked = is_clicked;
    but->is_hover = is_hover;
    return but;
}

cursor_t *init_cursor(sfVector2f origin, sfVector2f pos, sfTexture *texture)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    cursor->button_cursor = sfCircleShape_create();
    sfCircleShape_setOrigin(cursor->button_cursor, origin);
    sfCircleShape_setTexture(cursor->button_cursor, texture, sfTrue);
    sfCircleShape_setRadius(cursor->button_cursor, 10);
    return cursor;
}
