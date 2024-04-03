/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** singleton
*/

#include "includes/my.h"

int *prev_count(void)
{
    static int prev_count = -1;

    prev_count = prev_count;
    return &prev_count;
}

int *get_pid(void)
{
    static int pid = 0;

    pid = pid;
    return &pid;
}

int *mode(void)
{
    static int mode = 0;

    mode = mode;
    return &mode;
}

int *attack_count(void)
{
    static int attack_count = 0;

    attack_count = attack_count;
    return &attack_count;
}

int *return_signal(void)
{
    static int return_signal = 0;

    return_signal = return_signal;
    return &return_signal;
}
