/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** strcpy
*/

#include <unistd.h>
#include "include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; i < my_strlen(src); i++) {
        dest[i] = src[i];
    }
    dest[my_strlen(src)] = '\0';
    return dest;
}
