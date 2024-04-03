/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** intput
*/


#include "includes/my.h"

int *int_to_pos(int pos)
{
    int *attack_pos = malloc(sizeof(int) * 2);

    attack_pos[0] = (pos / 10) - 1;
    attack_pos[1] = (pos % 10) - 1;
    return attack_pos;
}

int is_shoot(int pos, char **map)
{
    int *attack_pos = int_to_pos(pos);

    if ((map[attack_pos[1]][attack_pos[0]] >= '2'
        && map[attack_pos[1]][attack_pos[0]] <= '8')
        || map[attack_pos[1]][attack_pos[0]] == 'x')
        return 0;
    else
        return 1;
}

char **attack_in_map(char **map, int pos)
{
    int *attack_pos = int_to_pos(pos);

    if (is_shoot(pos, map) == 0)
        map[attack_pos[1]][attack_pos[0]] = 'x';
    else
        map[attack_pos[1]][attack_pos[0]] = 'o';
    return map;
}
