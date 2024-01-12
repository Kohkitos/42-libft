# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/26 13:06:42 by fsanz-go          #+#    #+#              #
#    Updated: 2024/01/12 10:45:21 by fsanz-go         ###   ########.fr        #
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
		ft_bzero.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putendl_fd.c

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJ_NAME = $(SRC:%.c=%.o)

OBJ_BONUS = $(BONUS:%.c=%.o)

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

B_OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_BONUS))

# RM

RM = rm -rf

# RULES

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

bonus: $(B_OBJ) $(NAME)
		$(AR) $(NAME) $(B_OBJ)

$(OBJ_PATH)/%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

clean:
	$(RM) $(OBJ_PATH)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
