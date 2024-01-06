# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 13:06:42 by fsanz-go          #+#    #+#              #
#    Updated: 2024/01/06 18:39:48 by fsanz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME

NAME = libft.a

# COMPILER

CC = cc
CFLAGS = -Wall -Wextra -Werror

CFLAGS += -I $(INC_PATH) -I $(SRC_PATH)

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
		ft_isprint.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_memset.c \
		ft_bzero.c

OBJ_NAME = $(SRC:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

# RM

RM = rm -rf

# RULES

.PHONY: all re clean fclean

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
