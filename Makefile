# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 13:15:03 by mkovoor           #+#    #+#              #
#    Updated: 2022/06/16 18:00:00 by mkovoor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

CLIENT	=  client

SERVER = server

CLIENT_BONUS = bclient

SERVER_BONUS = bserver

SCRS_BONUS = server_bonus.c client_bonus.c

OBJS_BONUS = $(SCRS_BONUS:.c=.o)

SRCS	= client.c server.c

OBJS	= $(SRCS:.c=.o)

NAME	= minitalk

all:		libft/libft.a $(SERVER) $(CLIENT)

libft/libft.a:	
	$(MAKE) all -C libft

$(NAME): libft/libft.a $(CLIENT) $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) libft/libft.a client.o -o client

$(SERVER): server.o
	$(CC) $(CFLAGS) libft/libft.a server.o -o server

$(SERVER_BONUS): server_bonus.o
	$(CC) $(CFLAGS) libft/libft.a server_bonus.o -o bserver

$(CLIENT_BONUS): client_bonus.o
	$(CC) $(CCFLAGS) libft/libft.a client_bonus.o -o bclient

bonus: 		libft/libft.a $(SERVER_BONUS) $(CLIENT_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			$(MAKE) clean -C libft

fclean:		clean
			$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
			$(MAKE) fclean -C libft

re:			fclean all

rebonus: 	fclean bonus


.PHONY:		all clean fclean re minitalk rebonus bonus