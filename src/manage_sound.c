/*
** EPITECH PROJECT, 2024
** B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
** File description:
** manage_sound
*/

#include "../my_rpg.h"

void manage_sound(sfBool sound, sfMusic *son)
{
    FILE *fd;
    char *volume = NULL;
    size_t n = 0;
    int vol = 0;

    if (sound) {
        fd = fopen("setting.txt", "rw");
        getline(&volume, &n, fd);
        while (my_strcmp(volume, "son :\n") != 0)
            getline(&volume, &n, fd);
        getline(&volume, &n, fd);
        vol = my_getnbr(volume);
        sfMusic_setVolume(son, vol);
        fclose(fd);
    }
    if (!sound)
        sfMusic_setVolume(son, 0);
}
