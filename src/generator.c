/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-settingup-alen.sarsen
** File description:
** generator.c
*/

#include "../include/my.h"
#include "../include/setting_up.h"

static int check_params(char *av, char *str)
{
    for (int i = 0; av[i] != '\0'; i++)
        if (av[i] < '0' || av[i] > '9') {
            my_dprintf(STDOUT_FILENO, "incorrect size\n");
            exit(84);
        }
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] == '.' || str[i] == 'o')) {
            my_dprintf(STDOUT_FILENO, "incorrect pattern\n");
            exit(84);
        }
    return SUCCESS;
}

char **generator(char **av)
{
    int len = my_getnbr(av[1]);
    char *pattern = av[2];
    char **board = malloc(sizeof(char *) * (len + 1));
    int cnt = 0;
    int j;
    int i;

    if (my_strlen(av[2]) == 0)
        exit(84);
    check_params(av[1], av[2]);
    for (i = 0; i < len; i++) {
        board[i] = malloc(sizeof(char) * (len + 1));
        for (j = 0; j < len; j++) {
            board[i][j] = pattern[cnt % my_strlen(pattern)];
            cnt++;
        }
        board[i][j] = '\0';
    }
    board[i] = NULL;
    return board;
}
