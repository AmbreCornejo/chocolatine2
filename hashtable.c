/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** hash_table
*/

#include "include/hashtable.h"
#include "include/my.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *table = malloc(sizeof(hashtable_t));

    if (len <= 0)
        return NULL;
    table->hash = hash;
    table->len = len;
    table->array = malloc(sizeof(list_t *) * len);
    for (int i = 0; i < len; i++)
        table->array[i] = NULL;
    return table;
}

void delete_hashtable(hashtable_t *ht)
{
    for (int i = 0; i < ht->len; i++)
        delete_list(&ht->array[i]);
    free(ht->array);
}
