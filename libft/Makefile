# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 00:20:03 by artprevo          #+#    #+#              #
#    Updated: 2018/11/24 12:21:44 by artprevo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

FLAGS = -Wall -Wextra -Werror

SRC/M = ft_memccpy.c     \
	ft_memmove.c     \
	ft_memchr.c      \
	ft_memcpy.c      \
	ft_memset.c		 \
	ft_memcmp.c		\
	ft_memalloc.c	\
	ft_memdel.c		

SRC/O = ft_atoi.c        \
	ft_bzero.c        \
	ft_tolower.c    \
	ft_toupper.c	\
	ft_itoa.c

SRC/L = ft_lstnew.c		\
	ft_lstdelone.c		\
	ft_lstdel.c			\
	ft_lstadd.c			\
	ft_lstiter.c		\
	ft_lstmap.c			\

SRC/I = ft_isalnum.c    \
	ft_isalpha.c    \
	ft_isascii.c    \
	ft_isdigit.c    \
	ft_isprint.c

SRC/P = ft_putchar.c    \
	ft_putstr.c        \
	ft_putendl.c    \
	ft_putnbr.c		\
	ft_putchar_fd.c	\
	ft_putstr_fd.c	\
	ft_putendl_fd.c	\
	ft_putnbr_fd.c	

SRC/S = ft_strlen.c        \
	ft_strdup.c        \
	ft_strcpy.c        \
	ft_strncpy.c    \
	ft_strcat.c        \
	ft_strncat.c    \
	ft_strlcat.c    \
	ft_strstr.c        \
	ft_strnstr.c    \
	ft_strchr.c        \
	ft_strrchr.c    \
	ft_strcmp.c        \
	ft_strncmp.c    \
	ft_strequ.c        \
	ft_strnequ.c    \
	ft_strmap.c        \
	ft_strmapi.c    \
	ft_striter.c    \
	ft_striteri.c    \
	ft_strnew.c        \
	ft_strdel.c        \
	ft_strclr.c		\
	ft_strsub.c		\
	ft_strjoin.c		\
	ft_strtrim.c		\
	ft_strsplit.c	

INC = libft.h
SRC = $(SRC/P) $(SRC/O) $(SRC/I) $(SRC/S) $(SRC/M) $(SRC/L)
OBJ = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ) :
	$(CC) $(FLAGS) -c $(SRC)

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
