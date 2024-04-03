/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** display_h
*/

#include "includes/my.h"

void display_h(char *str)
{
    str = str;
    if (my_strcmp(str, "-h") == 0) {
        write(1, "USAGE\n\t./navy [first_player_pid]", 32);
        write(1, " navy_positions\n", 16);
        write(1, "DESCRIPTION\n\tfirst_player_pid:", 31);
        write(1, "only for the 2nd player. pid of the first player.\n", 50);
        write(1, "\tnavy_positions: file representing the positions", 48);
        write(1, " of the ships.\n", 15);
    }
}

void display_pid(void)
{
    write(1, "my_pid: ", 8);
    my_put_nbr(getpid());
    write(1, "\n", 1);
}

static void write_space(int j)
{
    if (j != 7)
        write(1, " ", 1);
}

void display_turn(char **map, int player)
{
    if (player == 1)
        write(1, "my navy:\n", 9);
    else
        write(1, "enemy navy:\n", 12);
    write(1, " |A B C D E F G H\n", 18);
    write(1, "-+---------------\n", 18);
    for (int i = 0; map[i] != NULL; i++) {
        my_put_nbr(i + 1);
        write(1, "|", 1);
        for (int j = 0; map[i][j] != '\0'; j++) {
            write(1, &map[i][j], 1);
            write_space(j);
        }
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}

void hit_or_miss(char *str, int boule)
{
    write(1, "\nresult: ", 9);
    write(1, &str[0], 1);
    write(1, &str[1], 1);
    if (boule == 0)
        write(1, ":missed\n\n", 9);
    else
        write(1, ":hit\n\n", 6);
}
