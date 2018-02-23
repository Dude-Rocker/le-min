# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgladush <vgladush@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 21:48:14 by vgladush          #+#    #+#              #
#    Updated: 2018/02/23 14:47:11 by vgladush         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

GC_FLGS = gcc -Wall -Wextra 

SRC_DIR = ./
INC_DIR = ./Includes/ $(LB_PATH)/Includes/
OBJ_DIR = ./obj/
LB_PATH = ./libft/
LB_LINK	= -L ./libft -lft

OBJ		= $(addprefix $(OBJ_DIR),$(OBJS))
INC		= $(addprefix -I, $(INC_DIR))

OBJS	= $(SRCS:.c=.o)

SRCS	= le_min.c ft_error.c ft_logic.c ft_resout.c ft_algoexit.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LB_PATH)
	@gcc -o $(NAME) $(OBJ) $(LB_LINK)
	@echo $(NAME) "ready"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(GC_FLGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LB_PATH) clean
	@rm -rf $(OBJ_DIR)

fclean:
	@make -C $(LB_PATH) fclean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@echo $(NAME) "deleted"

re: fclean all
