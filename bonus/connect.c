/*
** EPITECH PROJECT, 2024
** B-PSU-100-MPL-1-1-navy-ambre.cornejo
** File description:
** connect
*/

#include "includes/my.h"

static int *flag_handle(void)
{
    static int flag = 1;

    flag = flag;
    return &flag;
}

void action(int signal, siginfo_t *info, void *nothing)
{
    nothing = nothing;
    if (signal == SIGUSR2) {
        if (*get_pid() == 0) {
            *flag_handle() = 0;
            *get_pid() = info->si_pid;
        } else {
            *return_signal() += 1;
        }
    }
    if (signal == SIGUSR1) {
        *attack_count() += 1;
    }
}

int connect(void)
{
    struct sigaction sa;

    sa.sa_handler = NULL;
    sa.sa_sigaction = &action;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_restorer = NULL;
    sigemptyset(&sa.sa_mask);
    write(1, "my_pid: ", 8);
    my_put_nbr(getpid());
    write(1, "\n\nwaiting for enemy connection...\n", 34);
    while (*flag_handle()) {
        if (sigaction(SIGUSR2, &sa, NULL) == -1) {
            return 84;
        }
    }
    return 0;
}
