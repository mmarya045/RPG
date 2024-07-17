/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** resolution
*/

#include "../my_rpg.h"

sfRenderWindow *resolution(sfRenderWindow *win, sfEvent event)
{
    static int i = 0;
    size_t count;
    const sfVideoMode* array = sfVideoMode_getFullscreenModes(&count);
    sfVideoMode video_mode;

    if (event.key.code == sfKeyP)
        i++;
    if (i > 4)
        i = 0;
    sfRenderWindow_setSize(win, (sfVector2u){array[i].width, array[i].height});
    return win;
}
