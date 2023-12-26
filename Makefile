# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 13:06:42 by fsanz-go          #+#    #+#              #
#    Updated: 2023/12/26 13:25:07 by fsanz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME

NAME = libft.a

# COMPILER

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

# PATH

OBJ_PATH = obj/

SRC_PATH = src/

INC_PATH = inc/

# SOURCES

SRC = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c

# RM

RM = rm -rf

# RULES

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
