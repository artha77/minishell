##
## Makefile for my_printf in /home/artha/printf
## 
## Made by dylan renard
## Login   <artha@epitech.net>
## 
## Started on  Mon Nov  7 15:05:57 2016 dylan renard
## Last update Sun Jan 22 20:08:36 2017 dylan renard
##

CC	= 	gcc

RM	= 	rm -f

NAME	= 	mysh

SRCS	=	src/xfunc.c	\
		src/utils.c	\
		src/built.c	\
		src/built2.c	\
		src/main.c	\

OBJS	= 	$(SRCS:.c=.o)

CFLAGS	+=	#-W -Wall -Werror -pedantic

CFLAGS	+=	-I./include/

LDFLAGS +=	-L./lib -lmy -lgnl

all: libmy $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAFS) $(LDFLAGS) -lncurses

libmy:
	@$(MAKE) -C lib/my

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C lib/my

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, re, all, fclean
