##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compiles my program
##

CC 	=	gcc

SRC	=	src/error.c \
		src/first_calculation.c	\
		src/init_struct.c	\
		src/process.c \
		src/search_biggest.c	\
		src/search_close_to_zero.c	\
		src/seconde_calculation.c	\
		src/third_calculation.c	\
		src/main.c

LIB	=	lib/free.c \
		lib/list_add.c \
		lib/list_get.c \
		lib/my_getnbr.c \
		lib/my_isneg.c \
		lib/my_put.c	\
		lib/my_revstr.c \
		lib/my_strcat.c \
		lib/my_strcmp.c \
		lib/my_strcpy.c \
		lib/my_strdup.c \
		lib/my_strlen.c \
		lib/my_str_is.c \
		lib/my_strncmp.c \
		lib/my_str_to_word_array.c \
		lib/my_strupcase.c \
		lib/my_swap.c \
		lib/cm_strtok.c

OBJ	=	$(SRC:.c=.o) $(LIB:.c=.o)

NAME	=	libmy.a

NAME_BIN	= 	109titration

LIBA	=	-L. -lmy

INCLUDES        =       -I includes/

CFLAGS	=	$(INCLUDES) -Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@$(CC) -o $(NAME_BIN) $(LIBA)
		@echo -e "\033[1;32mCompilation done\033[0m"

%.o:	%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@find . \( -name "*~" -o -name "#*" -o -name "*#" \) -delete
	@echo -e "\033[1;31mClean done\033[0m"

fclean:	clean
	@rm -f $(NAME)
	@rm -f $(NAME_BIN)
	@rm -f coding-style-reports.log
	@rm -f vgcore*
	@echo -e "\033[1;31mFclean done\033[0m"

re:	fclean all

.PHONY: 	all re clean fclean
