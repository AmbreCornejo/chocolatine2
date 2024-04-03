/*
** EPITECH PROJECT, 2023
** day06
** File description:
** my_strcmp
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    char c1;
    char c2;

    while (1) {
        c1 = *s1;
        s1++;
        c2 = *s2;
        s2++;
        if (c1 != c2 || c1 == '\0') {
            break;
        }
    }
    return c1 - c2;
}
