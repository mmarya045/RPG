/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** close_window
*/

#include "../my_rpg.h"

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void handle_close_window(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        close_window(window);
}
