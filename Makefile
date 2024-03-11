# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/23 11:33:24 by mcid-baq          #+#    #+#              #
#    Updated: 2024/02/23 10:03:25 by mcid-baq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = gcc -g
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h

RSC = push_swap.c

RSC_BONUS = checker.c

C_RSC = utils/ft_split.c \
	utils/cost.c \
	utils/initialization.c \
	utils/push.c \
	utils/rotate.c \
	utils/rotate_reverse.c \
	utils/sort.c \
	utils/sort_list.c \
	utils/swap.c \
	utils/utils.c \

OBJ = $(RSC:.c=.o)
OBJ_BONUS = $(RSC_BONUS:.c=.o)
C_OBJS = $(C_RSC:.c=.o)

all : $(NAME) 

$(NAME): $(C_OBJS) $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(C_OBJS) $(OBJ) -o $(NAME)
	@echo "\033[32mALL COMPILED! YOU CAN START!\033[0m"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(C_OBJS) $(OBJ_BONUS) $(HEADER)
	@$(CC) $(FLAGS) $(C_OBJS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "\033[31mALL BONUS COMPILED! YOU CAN START!\033[0m"

%.o : %.c
	$(CC) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_BONUS) $(C_OBJS)
	@echo "\033[33m OBJECTS CLEANED!!\033[0m"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: re all clean fclean bonus