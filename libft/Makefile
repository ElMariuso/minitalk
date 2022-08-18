# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/07 16:36:01 by mthiry            #+#    #+#              #
#    Updated: 2022/03/18 11:41:50 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I. -c
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_strtrim.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_split.c \
	   ft_freestrjoin.c \
	   get_next_line.c \
	   ft_c_displaying.c \
	   ft_s_displaying.c \
	   ft_p_displaying.c \
	   ft_d_and_i_displaying.c \
	   ft_u_displaying.c \
	   ft_x_displaying.c \
	   ft_x_up_displaying.c \
	   ft_percent_displaying.c \
	   ft_check_next_char.c \
	   ft_check_format.c \
	   ft_printf.c \
	   ft_lstnew.c \
	   ft_lstadd_front.c \
	   ft_lstsize.c \
	   ft_lstlast.c \
	   ft_lstadd_back.c \
	   ft_lstdelone.c \
	   ft_lstclear.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_utoa.c \
	   ft_8bit_conversions.c \
	   ft_hexa_conversions.c \
	   ft_hexa_neg.c \
	   ft_hexa_pos.c \
	   ft_int_conversions.c \

OBJS = $(SRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
