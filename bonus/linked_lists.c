/*
** EPITECH PROJECT, 2023
** B-CPE-110-MPL-1-1-bsorganized-alexyan.comino
** File description:
** linked_lists
*/

#include "include/linked_lists.h"
#include "include/my.h"
#include <stdlib.h>

void push_to_front(list_t **head, int key, char *value)
{
    list_t *new_node = (list_t *)malloc(sizeof(list_t));

        new_node->value = value;
        new_node->key = key;
        new_node->value = my_strdup(value);
        new_node->next = *head;
        *head = new_node;
}

static int pop(list_t **list)
{
    list_t *next_node = NULL;

    next_node = (*list)->next;
    free(*list);
    *list = next_node;
    return 0;
}

int del(list_t **current, list_t **list, list_t **temp, int key)
{
    if ((*current)->key == key) {
        return (pop(list));
        (*temp) = *list;
    } else if ((*current)->next != NULL &&
        (*current)->next->key == key) {
        (*temp) = (*current)->next->next;
        free((*current)->next);
        (*current)->next = (*temp);
        return 0;
    } else {
        (*current) = (*current)->next;
    }
    return 1;
}

int delete_in_list(list_t **list, int key)
{
    list_t *current = *list;
    list_t *temp = NULL;
    int value = 0;

    if (current == NULL)
        return 84;
    while (current != NULL) {
        if (del(&current, list, &temp, key) == 1)
            value = 84;
    }
    return value;
}

int delete_list(list_t **head)
{
    list_t *current = *head;
    list_t *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    return 0;
}

int display_list(list_t *begin)
{
    list_t *current = begin;

    while (current != NULL) {
        if (current->key != '\0') {
            my_putstr("> ");
            my_put_nbr(current->key);
            my_putstr(" - ");
            my_putstr(current->value);
            my_putstr("\n");
        }
        current = current->next;
    }
    return 0;
}
