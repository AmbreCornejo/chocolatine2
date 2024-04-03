/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** load
*/

#include "includes/my.h"

char *open_read(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer = malloc(sizeof(char) * 32);
    int size;

    if (fd == -1)
        return NULL;
    size = read(fd, buffer, 32);
    buffer[size] = '\0';
    return buffer;
}

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 9);

    for (int i = 0; i < 8; i++) {
        map[i] = malloc(sizeof(char) * 9);
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
        map[i][8] = '\0';
    }
    map[8] = NULL;
    return map;
}

char **load_2d_array(char *str)
{
    int nb = nb_row(str);
    char **arr = malloc(sizeof(char *) * (nb + 1));
    int x = 0;
    int y = 0;

    for (int i = 0; i < nb; i++)
        arr[i] = malloc(sizeof(char) * 8);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n' && str[i + 1] != '\0') {
            x++;
            y = 0;
        } else {
            arr[x][y] = str[i];
            y++;
        }
    }
    arr[nb - 1][7] = '\0';
    arr[nb] = NULL;
    return arr;
}

char **str_in_array(char *str)
{
    char **array = malloc(sizeof(char *) * 3);
    int i = 0;
    int j = 0;
    int k = 0;

    while (str[i] != '\0') {
        array[k] = malloc(sizeof(char) * 2);
        while (str[i] == ':' || str[i] == '\n')
            i++;
        j = 0;
        while (str[i] != ':' && str[i] != '\n' && str[i] != '\0') {
            array[k][j] = str[i];
            i++;
            j++;
        }
        array[k][j] = '\0';
        k++;
    }
    array[k] = NULL;
    return array;
}

char **load_map(char *str)
{
    char **map;

    map = parsing(str);
    if (map == NULL)
        return NULL;
    return map;
}
