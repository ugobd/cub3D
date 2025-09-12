# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thphilip <thphilip@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 11:13:20 by thphilip          #+#    #+#              #
#    Updated: 2025/05/06 13:57:09 by thphilip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

SRC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_free_array.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_iswhitespace.c \
	ft_itoa.c\
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strcmp.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strjoinf.c \
	ft_striteri.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strlenc.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strndup.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	put_all_1.c \
	put_all_2.c \
	ft_printf.c \
	put_all_fd.c \
	ft_printf_fd.c \
	get_next_line.c \
	get_next_line_bonus.c

DIR_OBJ = obj/

OBJ = $(addprefix obj/, $(SRC:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

all : $(OBJ) $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

$(DIR_OBJ)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ) $(DIR_OBJ)

fclean:
		rm -rf $(NAME) $(OBJ) $(DIR_OBJ)

re:		fclean all

.PHONY: all clean fclean re
