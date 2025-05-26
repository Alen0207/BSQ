/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** Made by Alen Sarsen
*/

#include <string.h>
#include "my.h"
#include "setting_up.h"

int get_length(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char **tab = read_file(fd);
    int len = my_getnbr(tab[0]);

    if (len <= 0)
        exit(84);
    return len;
}

int count_size(char **tab, char **av)
{
    int len = get_length(av);
    int size;
    int cols = 0;

    while (tab[1][cols] != '\0')
        cols++;
    size = len * (cols + 1) + strlen(tab[0]) + 1;
    return size;
}

static int check_file(char **av)
{
    int fd = open(av[1], O_RDONLY);
    char **tab = read_file(fd);
    struct stat filestat;
    int size = count_size(tab, av);
    int right_size;

    if (!tab)
        return ERROR;
    if (stat(av[1], &filestat) == -1)
        return ERROR;
    right_size = filestat.st_size;
    if (right_size != size)
        exit(84);
    for (int i = 0; tab[0][i] != '\0'; i++) {
        if (tab[0][i] < '0' || tab[0][i] > '9')
            exit(84);
    }
    return SUCCESS;
}

int setting_up(int ac, char **av)
{
    int fd;

    if (ac == 2) {
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
            my_dprintf(STDOUT_FILENO, "Error with opening the file\n");
            exit(84);
        }
        if (check_file(av) == ERROR)
            return ERROR;
        get_biggest_square(find_square_from_file(fd), get_length(av));
        close(fd);
    } else if (ac == 3) {
        get_biggest_square(generator(av), my_getnbr(av[1]));
    } else {
        my_dprintf(STDOUT_FILENO, "incorrect number of parameters\n");
        exit(84);
    }
    return SUCCESS;
}
