# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhonore <qhonore@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 16:05:27 by qhonore           #+#    #+#              #
#    Updated: 2016/02/28 21:40:30 by qhonore          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/
LIB_PATH = ./lib/

SRC_NAME = main.c menu.c other.c render.c \
			checker.c game.c ia.c min_max.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft -lncurses
NAME = puissance4

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)libft/
	@cp $(LIB_PATH)libft/libft.a $(LIB_PATH)

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@echo "\033[37;44m Fclean libft \033[0m"
	@make -C $(LIB_PATH)libft/ fclean
	@echo "\033[37;44m Fclean $(NAME) \033[0m"
	rm -f $(NAME)

git:
	make fclean
	git add --a

pull:
	git fetch
	git pull

re: fclean all
