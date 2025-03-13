# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yourname <your.email@example.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 by yourname                   #+#    #+#              #
#    Updated: 2025/03/13 by yourname                  ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names
NAME    = push_swap
BONUS   = checker

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Source files for the main parts
PS_MAIN     = push_swap.c   # Contains main() for push_swap
CHK_MAIN    = checker.c     # Contains main() for checker

# Common source files shared by both executables (no main() here)
COMMON_SRCS = sort_small.c sort_large.c operations.c utils.c helper.c

# Object files: Convert source filenames to .o filenames.
PS_OBJS     = $(PS_MAIN:.c=.o)
CHK_OBJS    = $(CHK_MAIN:.c=.o)
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

# ---------------------------------------------------------------------------- #
# Rules
# ---------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(PS_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(PS_OBJS) $(COMMON_OBJS)

bonus: $(BONUS)

$(BONUS): $(CHK_OBJS) $(COMMON_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS) $(CHK_OBJS) $(COMMON_OBJS)

clean:
	rm -f $(PS_OBJS) $(CHK_OBJS) $(COMMON_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
