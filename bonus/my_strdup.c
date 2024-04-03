/*
** EPITECH PROJECT, 2023
** B-CPE-110-MPL-1-1-organized-alexyan.comino
** File description:
** my_strdup
*/

#include "include/my.h"

char *my_strdup(const char *str)
{
    int len = my_strlen(str) + 1;
    char *dest = (char *)malloc(len);

    my_strcpy(dest, str);
    return dest;
}
