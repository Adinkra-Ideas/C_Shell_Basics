# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 22:09:40 by euyi              #+#    #+#              #
#    Updated: 2021/12/04 10:32:45 by euyi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c \
	ft_isprint.c	ft_strlen.c	ft_memset.c	ft_bzero.c	ft_memcpy.c \
	ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	ft_putchar_fd.c \
	ft_toupper.c	ft_tolower.c	ft_strchr.c	ft_strrchr.c \
	ft_strncmp.c	ft_memchr.c	ft_memcmp.c	ft_strnstr.c	ft_atoi.c \
	ft_calloc.c	ft_strdup.c	ft_substr.c	ft_strjoin.c	ft_strtrim.c \
	ft_split.c	ft_itoa.c	ft_strmapi.c	ft_striteri.c \
	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c 


# $(subst from,to,gg) make object files from c files
OBJ = $(subst .c,.o,$(SRC))

BSRC = ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c \
	ft_lstadd_back.c	ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c 

# $(subst from,to,gg) make object files from c files for our bonus files
BOBJ = $(subst .c,.o,$(BSRC))

CC ?= cc

CFLAGS = -Wall	-Werror	-Wextra

all: $(NAME)

# cc -Wall -Werror -Wextra -c -o *.c ar rc libft.a *.o
$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

# cc -Wall -Werror -Wextra -c -o *.c ar rc libft.a *.o
bonus: $(BOBJ)
	ar rc $(NAME) $(BOBJ)

# Delete all object files only
clean:
	/bin/rm -f $(OBJ) $(BOBJ)

# Delete all object and executable files
fclean: clean
	/bin/rm -f $(NAME)

# Repeat fclean and recompile all mandatory functions
re: fclean all

# The following are Rule declarations
.PHONY:	all	clean	fclean	re bonus
