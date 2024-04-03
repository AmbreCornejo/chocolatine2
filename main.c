/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *hashtable = new_hashtable(&hash, 11);

    ht_insert(hashtable, "Vision", "vision");
    ht_insert(hashtable, "ababba", "boubou");
    ht_insert(hashtable, "", "vuy");
    ht_insert(hashtable, "abc", "test3");
    ht_insert(hashtable, "test", "test");
    ht_insert(hashtable, "test4", "test4");
    ht_insert(hashtable, "test", "test");
    ht_insert(hashtable, "test6", "test6");
    ht_delete(hashtable, "test3");
    ht_dump(hashtable);
    return 0;
}
