/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** win
*/

#include "includes/my.h"

int number_in_line(char **map, int i)
{
    for (int j = 0; map[i][j] != '\0'; j++)
        if (map[i][j] >= '2' && map[i][j] <= '8')
                return 0;
    return 1;
}

int is_win(char **map)
{
    for (int i = 0; i < 8; i++)
        if (number_in_line(map, i) == 0)
            return 0;
    return 1;
}
