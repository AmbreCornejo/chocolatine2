/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** my
*/

#pragma once
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include "struct.h"

int my_strcmp(char const *s1, char const *s2);
void display_h(char *str);
void my_put_nbr(int nb);
void my_putchar(char c);
void display_pid(void);
void display_turn(char **map, int player);
char **create_map(void);
char *open_read(char *filepath);
int my_strlen(char const *str);
char **str_in_array(char *str);
char **load_2d_array(char *str);
char **parsing(char *path);
int connect(void);
int my_getnbr(char const *str);
int bad_file(int *boat_pos, char **pos);
int bad_str(char *str);
int same_boat_len(int *len_boat);
int nb_row(char *str);
int letter_to_int(char c);
char **attack_in_map(char **map, int pos);
int *get_pid(void);
int *mode(void);
int *attack_count(void);
int *prev_count(void);
void action(int signal, siginfo_t *info, void *nothing);
int player1(navy_t *navy);
int player2(navy_t *navy, char **av);
char **load_map(char *str);
int bad_attack(char *str);
int *prev_count(void);
int *get_pid(void);
int *mode(void);
int *attack_count(void);
int *return_signal(void);
int is_shoot(int pos, char **map);
int *int_to_pos(int pos);
int is_win(char **map);
void hit_or_miss(char *str, int bool);
