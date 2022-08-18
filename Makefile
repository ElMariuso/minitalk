# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 12:17:50 by mthiry            #+#    #+#              #
#    Updated: 2022/03/24 18:37:33 by mthiry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror 

SRCS_SERVER =	main_server.c \

SRCS_CLIENT =	main_client.c \

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

%.o : %.c
	@tput setaf 32 && echo [Making Objects]
	@tput setaf 34
	$(CC) $(CFLAGS) -c $? -o $(?:.c=.o)
	@tput setaf 32 && echo [Objects Done]

all: $(NAME)

$(LIBFT):
	@tput setaf 32 && echo [Making Libft]
	@tput setaf 34
	@make -C libft/
	@tput setaf 32 && echo [Libft Compiled]
	@echo ---------------------------------

$(SERVER): $(LIBFT) $(OBJS_SERVER)
	@tput setaf 32 && echo [Making Server]
	@tput setaf 34
	$(CC) $(CFLAGS) -o $@ $^
	@tput setaf 32 && echo [Server Compiled]
	@echo ---------------------------------

$(CLIENT): $(LIBFT) $(OBJS_CLIENT)
	@tput setaf 32 && echo [Making Client]
	@tput setaf 34
	$(CC) $(CFLAGS) -o $@ $^
	@tput setaf 32 && echo [Client Compiled]
	@echo ---------------------------------

$(NAME): $(LIBFT) $(SERVER) $(CLIENT)

clean:
	@tput setaf 35
	@make clean -C libft/
	rm -f $(OBJS_SERVER) 
	rm -f $(OBJS_CLIENT)
	@tput setaf 31 && echo Deleted Objects from Libft and from root!
	@echo ---------------------------------

fclean: clean
	@tput setaf 35
	rm -rf $(LIBFT) 
	rm -rf $(SERVER) $(CLIENT)
	@tput setaf 31 && echo Deleted Server, Client and Libft!
	@echo ---------------------------------

re: fclean all

.PHONY: all clean fclean re