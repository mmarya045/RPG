/*
** EPITECH PROJECT, 2024
** ..
** File description:
** button_clicked
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "../my_rpg.h"
#include <stdlib.h>

void change_button_sound(button_t *button)
{
    static sfBool mute = sfFalse;
    sfTexture *sound_text = sfTexture_createFromFile(MUTE, NULL);
    sfVector2f pos_button = sfRectangleShape_getPosition(button->rect);
    sfVector2f size_button = sfRectangleShape_getSize(button->rect);

    if (mute)
        sound_text = sfTexture_createFromFile(SOUND_BUTTON, NULL);
    button = init_button(pos_button, size_button, sound_text, button);
    mute = !mute;
}

sfBool is_hover(button_t *button, sfMouseMoveEvent *event)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);

    if (event->x >= button_pos.x && event->x <= button_pos.x + button_size.x &&
    event->y >= button_pos.y && event->y <= button_pos.y + button_size.y) {
        sfRectangleShape_setOutlineThickness(button->rect, 5);
        sfRectangleShape_setOutlineColor(button->rect, sfWhite);
        return sfTrue;
    }
    sfRectangleShape_setOutlineColor(button->rect, sfTransparent);
    return sfFalse;
}

sfBool is_clicked(button_t *button, sfMouseButtonEvent *event)
{
    sfVector2f button_pos = sfRectangleShape_getPosition(button->rect);
    sfVector2f button_size = sfRectangleShape_getSize(button->rect);
    sfClock *clock = sfClock_create();
    sfTime elapsed;

    if (event->x >= button_pos.x && event->x <= button_pos.x + button_size.x &&
    event->y >= button_pos.y && event->y <= button_pos.y + button_size.y) {
        sfRectangleShape_setOutlineColor(button->rect, sfGreen);
        return sfTrue;
    }
    return sfFalse;
}
