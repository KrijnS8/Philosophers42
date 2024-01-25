# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kschelvi <kschelvi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/15 16:37:50 by kschelvi      #+#    #+#                  #
#    Updated: 2024/01/25 15:19:18 by kschelvi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo
CFLAGS = -Wall -Wextra -Werror -g -pthread -I incl/
SANITIZE_FLAGS = -fsanitize=thread

SRC = src/main.c src/errors.c src/config.c src/philosopher.c src/simulation.c src/fork.c src/philo_actions.c
SRC_UTILS = src/utils/ft_atoi.c src/utils/ft_is_integer.c src/utils/ft_isdigit.c src/utils/ft_strlen.c src/utils/ft_strncmp.c

OBJ = $(SRC:%.c=%.o)
OBJ_UTILS = $(SRC_UTILS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(OBJ) $(OBJ_UTILS) -o $(NAME)

sanitize: $(OBJ) $(OBJ_UTILS)
	$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(OBJ) $(OBJ_UTILS) -o $(NAME)

clean:
	$(RM) -rf $(OBJ) $(OBJ_UTILS)

fclean:
	$(RM) -rf $(OBJ) $(OBJ_UTILS) $(NAME)

re: fclean all

.PHONY: all clean fclean
