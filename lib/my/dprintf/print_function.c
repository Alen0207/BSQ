/*
** EPITECH PROJECT, 2025
** lib
** File description:
** dprint function
*/


#include "my.h"
#include <unistd.h>

static void integer_print(int fd, int nb)
{
    char char_nb = 0;

    if (nb == 0)
        write(fd, "0", CHAR_SIZE);
    if (nb < 0){
        write(fd, "-", CHAR_SIZE);
        nb = -nb;
    }
    for (nb = nb; nb > 0; nb /= 10){
        char_nb = ('0' + (nb % 10));
        write(fd, &char_nb, CHAR_SIZE);
    }
}

void print_hexa(int fd, va_list arg)
{
    int rest = 0;
    char buffer[30];
    int quo = rev_nbr(va_arg(arg, int));
    int k = 0;

    for (; quo != 0; k++) {
    rest = quo % 16;
    quo = quo / 16;
    buffer[k] = (rest < 10) ? ('0' + rest) : ('a' + (rest - 10));
    }
    k = k - 1;
    for (; k >= 0; k--) {
        write(fd, &buffer[k], 1);
    }
}

void print_nbr(int fd, va_list arg)
{
    int nb = rev_nbr(va_arg(arg, int));

    integer_print(fd, nb);
}

void print_str(int fd, va_list arg)
{
    char *str = va_arg(arg, char *);

    write(fd, str, my_strlen(str));
}

void print_float(int fd, va_list arg)
{
    float fnbr = (float)va_arg(arg, double);
    int integer = rev_nbr((int)fnbr);
    char char_float = 0;

    integer_print(fd, integer);
    write(fd, ".", CHAR_SIZE);
    fnbr -= integer;
    for (size_t i = 0; i < 6; i++){
        char_float = ('0' + (int)fnbr % 10);
        write(fd, &char_float, CHAR_SIZE);
        fnbr *= 10;
    }
}

void print_char(int fd, va_list arg)
{
    char c = va_arg(arg, int);

    write(fd, &c, CHAR_SIZE);
}
