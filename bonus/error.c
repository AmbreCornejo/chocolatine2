/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** error
*/

#include "includes/my.h"

int bad_file(int *boat_pos, char **pos)
{
    pos = pos;
    if ((boat_pos[0] < '1' || boat_pos[0] > '8')
        || (boat_pos[1] < 0 || boat_pos[1] > 8)
        || (boat_pos[2] < 1 || boat_pos[2] > 8)
        || (boat_pos[3] < 0 || boat_pos[3] > 8)
        || (boat_pos[4] < 1 || boat_pos[4] > 8)
        || (my_strlen(pos[0]) != 1) || (my_strlen(pos[1]) != 2)
        || (my_strlen(pos[2]) != 2))
        return 84;
    return 0;
}

int bad_str(char *str)
{
    if ((str[1] != ':' || str[4] != ':')
        || (my_strlen(str) != 7))
        return 84;
    return 0;
}

int bad_attack(char *str)
{
    if (str == NULL)
        return 84;
    if (my_strlen(str) != 3)
        return 84;
    if ((str[0] < 'A' || str[0] > 'H') ||
        (str[1] < '1' || str[1] > '8'))
        return 84;
    return 0;
}

static int is_same(int i, int j, int *len_boat)
{
    if (i != j) {
        if (len_boat[i] == len_boat[j])
            return 84;
    }
    return 0;
}

static int loop_for_boat_len(int i, int *len_boat)
{
    for (int j = 0; j < 4; j++) {
        if (is_same(i, j, len_boat) == 84)
            return 84;
    }
    return 1;
}

int same_boat_len(int *len_boat)
{
    for (int i = 0; i < 4; i++) {
        if (loop_for_boat_len(i, len_boat) == 84)
            return 84;
    }
    return 0;
}
