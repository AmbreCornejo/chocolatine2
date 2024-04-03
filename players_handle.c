/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** players_handle
*/

#include "includes/my.h"

static char *wrong_postion(char *str)
{
    size_t len = 0;

    while (bad_attack(str) == 84) {
        if (str != NULL)
            write(1, "\nwrong position\n\nattack: ", 25);
        while (getline(&str, &len, stdin) == -1);
    }
    return str;
}

static int shoot(char *attack, navy_t *navy)
{
    display_turn(navy->map, 1);
    display_turn(navy->enemy_map, 2);
    if (is_shoot(*attack_count(), navy->map) == 0) {
        navy->map = attack_in_map(navy->map, *attack_count());
        kill(navy->enemy_pid, SIGUSR2);
        hit_or_miss(attack, 1);
        if (is_win(navy->map) == 1) {
            usleep(1000);
            kill(navy->enemy_pid, SIGUSR2);
            display_turn(navy->map, 1);
            display_turn(navy->enemy_map, 2);
            write(1, "Enemy won\n", 10);
            return 1;
        }
    } else
        hit_or_miss(attack, 0);
    return 0;
}

static int loop_end(navy_t *navy)
{
    char *attack = malloc(sizeof(char) * 3);

    if (*attack_count() == *prev_count()) {
        attack[0] = (char)((*attack_count() / 10) + 'A' - 1);
        attack[1] = (char)((*attack_count() % 10) + '0');
        attack[2] = '\0';
        write(1, "\n", 1);
        if (shoot(attack, navy) == 1)
            return 1;
        *mode() = 1;
    }
    return 0;
}

static void send_and_receive(int pos_value, navy_t *navy, struct sigaction *sa)
{
    for (int i = 0; i < pos_value; i++) {
        kill(navy->enemy_pid, SIGUSR1);
        usleep(1000);
    }
    for (int i = 0; i < 10; i++) {
        sigaction(SIGUSR2, sa, NULL);
        usleep(10000);
    }
    *mode() = 0;
}

static void get_signal(int *attack_pos, navy_t *navy, char *str)
{
    if (*return_signal() == 0) {
        hit_or_miss(str, 0);
        navy->enemy_map[attack_pos[1]][attack_pos[0]] = 'o';
    }
    if (*return_signal() > 0) {
        hit_or_miss(str, 1);
        navy->enemy_map[attack_pos[1]][attack_pos[0]] = 'x';
    }
}

int attack(struct sigaction *sa, navy_t *navy)
{
    char *str = NULL;
    int pos_value = 0;
    int *attack_pos = NULL;

    while (*mode() == 1) {
        write(1, "attack: ", 8);
        str = wrong_postion(str);
        pos_value = ((str[0] - 'A' + 1) * 10) + (str[1] - '0');
        send_and_receive(pos_value, navy, sa);
        attack_pos = int_to_pos(pos_value);
        get_signal(attack_pos, navy, str);
        if (*return_signal() == 2) {
            display_turn(navy->map, 1);
            display_turn(navy->enemy_map, 2);
            write(1, "I won\n", 6);
            return 1;
        }
        navy->enemy_map = attack_in_map(navy->enemy_map, pos_value);
    }
    return 0;
}

int wait_attack(struct sigaction *sa, navy_t *navy)
{
    write(1, "waiting for enemy's attack...", 29);
    while (*mode() == 0) {
        *prev_count() = (*attack_count() != 0) ? *attack_count() : -1;
        sigaction(SIGUSR1, sa, NULL);
        usleep(10000);
        if (loop_end(navy) == 1)
            return 1;
    }
    *attack_count() = 0;
    *return_signal() = 0;
    return 0;
}

int turn_handling(navy_t *navy)
{
    struct sigaction sa;

    sa.sa_handler = NULL;
    sa.sa_sigaction = &action;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_restorer = NULL;
    sigemptyset(&sa.sa_mask);
    if (attack(&sa, navy) == 1)
        return 1;
    if (wait_attack(&sa, navy) == 1)
        return 1;
    return 0;
}

int player1(navy_t *navy)
{
    *mode() = 1;
    if (connect() == 84)
        return 84;
    navy->enemy_pid = *get_pid();
    write(1, "\nenemy connected\n", 17);
    display_turn(navy->map, 1);
    display_turn(navy->enemy_map, 2);
    while (1) {
        if (turn_handling(navy) == 1)
            break;
    }
    return 0;
}

int player2(navy_t *navy, char **av)
{
    *mode() = 0;
    *get_pid() = -1;
    write(1, "my_pid: ", 8);
    my_put_nbr(getpid());
    write(1, "\n\nsuccessfully connected\n", 25);
    kill(navy->enemy_pid, SIGUSR2);
    av = av;
    display_turn(navy->map, 1);
    display_turn(navy->enemy_map, 2);
    while (1) {
        if (turn_handling(navy) == 1)
            break;
    }
    return 0;
}
