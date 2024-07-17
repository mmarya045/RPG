/*
** EPITECH PROJECT, 2024
** ..
** File description:
** my_getnbr
*/

#include "../my_rpg.h"

int my_getnbr(const char *str)
{
    int i = 0;
    int nb = 0;
    int sign = 1;

    while (str[i] == '-' || str[i] == '+' || str[i] == ' ') {
        if (str[i] == '-') {
            sign = -sign;
        }
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10;
        nb += (str[i] - 48);
        i += 1;
    }
    if (sign == -1) {
        nb = nb * sign;
    }
    return nb;
}
