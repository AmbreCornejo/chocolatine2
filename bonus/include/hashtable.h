/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** hash_table
*/

#pragma once

#include "linked_lists.h"
#include <stdlib.h>

typedef struct hashtable_s {
    int (*hash)(char *, int);
    int len;
    list_t **array;
} hashtable_t;

int hash(char *key, int len);
hashtable_t *new_hashtable(int (*hash)(char *, int), int len);
void delete_hashtable(hashtable_t *ht);
int ht_insert(hashtable_t *ht, char *key, char *value);
int ht_delete(hashtable_t *ht, char *key);
char *ht_search(hashtable_t *ht, char *key);
void ht_dump(hashtable_t *ht);
int ht_edit(hashtable_t *ht, char *key, char *value);
