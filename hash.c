/*
** EPITECH PROJECT, 2023
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** hash
*/

#include "include/hashtable.h"
#include "include/my.h"

int hash(char *key, int len)
{
    int h = 0;

    len = len;
    while (*key != '\0') {
        h += *key;
        h += (h << 10);
        h ^= (h >> 6);
        key++;
    }
    h += (h << 3);
    h ^= (h >> 11);
    h += (h << 15);
    if (h < 0)
        h = -h;
    return h;
}
