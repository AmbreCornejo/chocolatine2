/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** parsing
*/

#include "includes/my.h"

int nb_row(char *str)
{
    int c = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] != '\0')
            c++;
    }
    return c;
}

int letter_to_int(char c)
{
    char *index = "ABCDEFGH";
    int pos = -1;

    for (int i = 0; index[i] != '\0'; i++) {
        if (index[i] == c)
            pos = i;
    }
    return pos;
}

int *get_boat_pos(char **pos)
{
    int *boat_pos = malloc(sizeof(int) * 7);

    boat_pos[0] = pos[0][0];
    boat_pos[1] = letter_to_int(pos[1][0]);
    boat_pos[2] = pos[1][1] - '0';
    boat_pos[3] = letter_to_int(pos[2][0]);
    boat_pos[4] = pos[2][1] - '0';
    boat_pos[5] = boat_pos[3] - boat_pos[1];
    boat_pos[6] = boat_pos[4] - boat_pos[2];
    return boat_pos;
}

char **place_boat_in_map(char **map, char **pos)
{
    int *boat_pos = get_boat_pos(pos);

    if (bad_file(boat_pos, pos) == 84)
        return NULL;
    if (boat_pos[5] == 0) {
        if (boat_pos[4] - boat_pos[2] + 1 != boat_pos[0] - '0')
            return NULL;
        for (int i = 0; i < boat_pos[6]; i++)
            map[boat_pos[2] + i][boat_pos[1]] = boat_pos[0];
    }
    if (boat_pos[6] == 0) {
        if (boat_pos[3] - boat_pos[1] + 1 != boat_pos[0] - '0')
            return NULL;
        for (int i = 0; i < boat_pos[5]; i++)
            map[boat_pos[2] - 1][boat_pos[1] + 1 + i] = boat_pos[0];
    }
    map[boat_pos[2] - 1][boat_pos[1]] = boat_pos[0];
    return map;
}

static char **temp(int *len_boat, char **pos, int c, char **map)
{
    len_boat[c] = pos[0][0];
    map = place_boat_in_map(map, pos);
    return map;
}

static int process_items(char **map, char *str)
{
    char **items;
    char **pos;
    int c = 0;
    int *len_boat = malloc(sizeof(int) * 4);

    if (len_boat == NULL)
        return 0;
    items = load_2d_array(str);
    for (int i = 0; items[i] != NULL; i++) {
        if (bad_str(items[i]) == 84)
            return 0;
        pos = str_in_array(items[i]);
        map = temp(len_boat, pos, c, map);
        if (map == NULL)
            return 0;
        c++;
    }
    if (c != 4 || same_boat_len(len_boat) == 84)
        return 0;
    return 1;
}

char **parsing(char *path)
{
    char **map = create_map();
    char *str = open_read(path);

    if (str == NULL)
        return NULL;
    if (!process_items(map, str))
        return NULL;
    return map;
}
