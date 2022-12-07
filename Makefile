# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by tnicoue           #+#    #+#              #
#    Updated: 2022/12/07 15:43:28 by kcatrix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

CLINK= -framework OpenGL -framework AppKit

SRCS = main.c parsing.c GNL/get_next_line.c GNL/get_next_line_utils.c parsing2.c \
		parsing3.c parsing4.c checkopen.c valfix.c errparsing.c closedmap.c \
		sky_and_floor.c init.c cube.c raycasting.c ft_key.c init2.c parsing5.c \
		ft_key2.c raycastin_25.c
RM = rm -f

ifndef BONUS
SOURCES	= ./srcs/
OBJS	= $(addprefix $(SOURCES),$(SRCS:.c=.o))
else
SOURCES	= ./srcs_bonus
OBJS	= $(SRCS_BONUS:.c=.o)
endif

LIBPATH = ./lib/libft/libft.a

all: ${NAME}

bonus:
	@echo "\033[1;32m""Compilation de ${NAME}..."
	@make BONUS=1 ${NAME}

${NAME}: ${OBJS}
		@echo "\033[1;36m""Compilation de ${NAME}..."
	   	@$(MAKE) -j -s --no-print-directory -C lib/libft
		$(CC) $(LIBPATH) $(OBJS) $(CFLAGS) $(CLINK) libmlx.a -lncurses -o $(NAME)

${OBJECTS}/%.o: ${SOURCES}/%.c
	@echo "Compilation de ${notdir $<}."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@echo "\033[1;32m""Supression des fichiers binaires (.o)..."
	   	@$(MAKE) -s --no-print-directory -C lib/libft/ clean
		${RM} ${OBJS}

fclean: clean
		@echo "\033[1;32m""Supression des executables et librairies..."
		@$(MAKE) -s --no-print-directory -C lib/libft/ fclean
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all
	@echo "\033[0m"

.PHONY: all clean fclean re

