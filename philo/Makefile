# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kschelvi <kschelvi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/15 16:37:50 by kschelvi      #+#    #+#                  #
#    Updated: 2024/01/19 15:28:34 by kschelvi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -pthread -I incl/

SRC = src/main.c src/errors.c src/config.c src/philosopher.c src/simulation.c src/fork.c
SRC_UTILS = src/utils/ft_atoi.c src/utils/ft_is_integer.c src/utils/ft_isdigit.c src/utils/ft_strlen.c src/utils/ft_strncmp.c

OBJ = $(SRC:%.c=%.o)
OBJ_UTILS = $(SRC_UTILS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) -o $(NAME)

clean:
	$(RM) -rf $(OBJ) $(OBJ_UTILS)

fclean:
	$(RM) -rf $(OBJ) $(OBJ_UTILS) $(NAME)

re: fclean all

.PHONY: all clean fclean
