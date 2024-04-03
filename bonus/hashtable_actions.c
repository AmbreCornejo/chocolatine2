/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** hashtable_actions
*/

#include "include/hashtable.h"
#include "include/my.h"

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    int index = (ht != NULL && key != NULL) ? ht->hash(key, ht->len) : 0;

    if (ht == NULL || key == NULL || value == NULL ||
        my_strlen(key) == 0 || my_strlen(value) == 0)
        return 84;
    if (ht_search(ht, key) != NULL) {
        ht_edit(ht, key, value);
        return 0;
    }
    push_to_front(&ht->array[index % ht->len], index, value);
    return 0;
}

int ht_delete(hashtable_t *ht, char *key)
{
    int index = (ht != NULL && key != NULL) ? ht->hash(key, ht->len) : 0;

    if (ht == NULL || key == NULL || my_strlen(key) == 0)
        return 84;
    return (delete_in_list(&ht->array[index % ht->len], index));
}

char *ht_search(hashtable_t *ht, char *key)
{
    int index = (ht != NULL && key != NULL) ?
        ht->hash(key, ht->len) : 0;
    list_t *tmp = (ht != NULL && key != NULL) ?
        ht->array[index % ht->len] : NULL;

    if (ht == NULL || key == NULL || my_strlen(key) == 0)
        return NULL;
    while (tmp != NULL) {
        if (tmp->key == index)
            return tmp->value;
        tmp = tmp->next;
    }
    return NULL;
}

void ht_dump(hashtable_t *ht)
{
    if (ht == NULL)
        return;
    for (int i = 0; i < ht->len; ++i) {
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        display_list(ht->array[i]);
    }
}

int ht_edit(hashtable_t *ht, char *key, char *value)
{
    int index = (ht != NULL && key != NULL) ? ht->hash(key, ht->len) : 0;
    list_t *tmp = (ht != NULL && key != NULL) ?
        ht->array[index % ht->len] : NULL;

    if (ht == NULL || key == NULL || value == NULL ||
        my_strlen(key) == 0 || my_strlen(value) == 0)
        return 84;
    while (tmp != NULL) {
        if (tmp->key == index) {
            tmp->value = value;
            return 0;
        }
        tmp = tmp->next;
    }
    return 84;
}
