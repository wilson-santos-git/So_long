# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:41:58 by wteles-d          #+#    #+#              #
#    Updated: 2023/12/17 01:27:34 by wteles-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = exit.c inits.c inputs.c libft_utils.c libft_utils2.c main.c map_check.c map.c player.c solve_game.c split.c parse_map.c parse_map_utils.c

OBJS = $(SRCS:.c=.o)

CC = cc

GNL = gnl/gnl.a

PRTF = ft_printf/ft_printf.a

FLAGS = -Wall -Werror -Wextra -g #-fsanitize=address

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I ft_printf -I gnl -I/usr/include -Imlx -O3 -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(GNL) $(PRTF)
	$(CC) $(OBJS) -L ft_printf -l:ft_printf.a -L gnl -l:gnl.a -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(GNL):
	make -C gnl
	
$(PRTF):
	make -C ft_printf
clean:
	@rm -f $(OBJS)

fclean:	clean 
	@rm -f $(NAME) $(GNL) $(PRTF)
	make fclean -C gnl
	make fclean -C ft_printf

re:	fclean all

.PHONY: all clean fclean re