##
## EPITECH PROJECT, 2018
## makefile
## File description:
## Runner Makefile Mai Ly Lehoux
##

CC		=	gcc

CFLAGS		=	-I./include -Wall -Wextra -g

GRAPH_FLAG	=	-lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

RM		=	rm -f

SRCS		=	src/main.c \
			src/heroe.c \
			src/str/my_strlen.c \
			src/backgrounds.c \
			src/str/my_strcmp.c \
			src/str/my_putstr.c \
			src/str/my_putchar.c \
			src/str/my_put_nbr.c \
			src/str/my_revstr.c \
			src/events.c \
			src/obstacles.c \
			src/errors.c \
			src/collisions.c \
			src/score.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	my_runner

all		:
		$(MAKE) $(NAME) --no-print-directory

$(NAME)		:	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(GRAPH_FLAG)

clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)
re		:
		$(MAKE) fclean --no-print-directory
		$(MAKE) all --no-print-directory

.PHONY: all clean fclean re
