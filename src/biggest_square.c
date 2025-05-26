/*
** EPITECH PROJECT, 2024
** B-CPE-110-PAR-1-1-settingup-alen.sarsen
** File description:
** biggest_square.c
*/

#include "../include/my.h"
#include "../include/setting_up.h"

void display_board(char **board, int len)
{
    for (int i = 0; i < len; i++)
        my_dprintf(STDOUT_FILENO, "%s\n", board[i]);
}

char **read_file(int fd)
{
    struct stat filestat;
    char *buff;
    char **tab;
    ssize_t bytes_read;

    if (fstat(fd, &filestat) == -1)
        return NULL;
    buff = malloc(sizeof(char) * (filestat.st_size + 1));
    if (!buff)
        return NULL;
    bytes_read = read(fd, buff, filestat.st_size);
    if (bytes_read == -1 || bytes_read != filestat.st_size) {
        free(buff);
        return NULL;
    }
    buff[filestat.st_size] = '\0';
    tab = my_str_to_word_arr(buff, "\n");
    free(buff);
    if (!tab || !tab[0])
        return NULL;
    return tab;
}

char **find_square_from_file(int fd)
{
    char **tab = read_file(fd);
    int len = my_getnbr(tab[0]);
    char **board = malloc(sizeof(char *) * (len + 1));
    int cnt = 1;

    for (int i = 0; i < len; i++) {
        board[i] = tab[cnt];
        cnt++;
    }
    board[len] = NULL;
    return board;
}

static int check_size(int size, int i, int j, square_t *square)
{
    for (int m = 0; m <= size; m++) {
        if (square->square[i + size][j + m] == 'o' ||
            square->square[i + m][j + size] == 'o')
            return SUCCESS;
    }
    return 1;
}

static void parse_board(int i, int j, square_t *square)
{
    int size = 0;

    while ((i + size) < square->length &&
        square->square[i + size][j + size] != '\0') {
        if (check_size(size, i, j, square) == 0)
            break;
        size++;
    }
    if (size > square->size) {
        square->size = size;
        square->coords[0] = i;
        square->coords[1] = j;
    }
}

void get_biggest_square(char **board, int len)
{
    square_t square;

    square.square = board;
    square.length = len;
    square.size = 0;
    for (int i = 0; square.square[i] != NULL; i++) {
        for (int j = 0; square.square[i][j] != '\0'; j++) {
            parse_board(i, j, &square);
        }
    }
    for (int i = square.coords[0]; i < square.size + square.coords[0]; i++) {
        for (int j = square.coords[1]; j < square.size + square.coords[1];
            j++) {
            square.square[i][j] = 'x';
        }
    }
    display_board(square.square, square.length);
}
