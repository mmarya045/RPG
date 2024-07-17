##
## EPITECH PROJECT, 2024
## B-MUL-200-RUN-2-1-myrpg-sacha.mong-hune
## File description:
## Makefile
##

SRC := $(shell find $(SRCDIR) -name "*.c")

OBJ = $(SRC:.c=.o)

NAME = my_rpg

FLAGS = -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

WFLAGS = -W -Wall -Werror -Wextra

all: $(NAME)

$(NAME):	$(OBJ)
			gcc $(SRC) -o $(NAME) $(FLAGS) -g3

clean:
		rm $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re: fclean all
