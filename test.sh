#!/bin/sh
cc -Wall -Werror -Wextra -pedantic -g3 -fsanitize=address -D PRINTER=printg cshell.c -o cshell
./cshell /bin/ls "|" /usr/bin/grep cshell ";" /bin/echo i love my cshell
rm cshell
