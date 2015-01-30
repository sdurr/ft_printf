#!/bin/sh

rm -f outprintf outftprintf
make re
gcc main_ftprintf.c -iquote header -iquote libft libftprintf.a libft/libft.a -o main_ftprintf
./main_ftprintf
diff outprintf outftprintf