/*
** EPITECH PROJECT, 2024
** B-CPE-110-MPL-1-1-secured-alexyan.comino
** File description:
** linked_lists
*/

#pragma once

typedef struct linked_list_s {
    int key;
    char *value;
    struct linked_list_s *next;
} list_t;

void push_to_front(list_t **head, int key, char *value);
int delete_in_list(list_t **list, int key);
int delete_list(list_t **head);
int display_list(list_t *begin);
