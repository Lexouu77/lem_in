# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 01:48:43 by ahamouda          #+#    #+#              #
#    Updated: 2016/03/26 23:20:45 by ahamouda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = clang
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -O3 -march=native
DEBUGFLAG = -g3 -fsanitize=address
INCLUDES = ./
OBJ = $(SRC:.c=.o)
SRC = add_line.c\
	  add_link.c\
	  check_info.c\
	  check_pipes.c\
	  convert_info.c\
	  get_file_info.c\
	  get_nb_ants.c\
	  get_nb_pipes.c\
	  get_nb_rooms.c\
	  get_paths.c\
	  lem_in.c\
	  move_ants.c\
	  resolve.c\
	  set_ants.c\
	  stock_room.c

HEADER = lem_in.h

#.SILENT:

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C libftprintf
	$(CC) -o $(NAME) $(SRC) $(CFLAGS) -L ./libftprintf/ -lftprintf

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I $(INCLUDES)

clean:
	$(RM) $(OBJ)
	make -C libftprintf clean

fclean: clean
	$(RM) $(NAME)
	make -C libftprintf fclean

re: fclean all

function:
	nm -u $(NAME)

.PHONY: re fclean clean all function
