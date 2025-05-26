/*
** EPITECH PROJECT, 2024
** setting_up.h
** File description:
** setting_up.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef SET_UP_H_
    #define SET_UP_H_
    #define SUCCESS 0
    #define ERROR   84

typedef struct square_s {
    int length;
    int size;
    char **square;
    char **temp;
    int coords[2];
} square_t;

void display_board(char **board, int len);
char **find_square_from_file(int fd);
void get_biggest_square(char **board, int len);
char **read_file(int fd);
char **generator(char **av);
int count_size(char **tab, char **av);
int setting_up(int ac, char **av);
int get_length(char **av);

#endif /* SET_UP_H_ */
