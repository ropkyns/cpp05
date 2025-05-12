# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paulmart <paulmart@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/21 14:08:25 by paulmart          #+#    #+#              #
#    Updated: 2025/05/12 17:37:26 by paulmart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form_Upgraded

CC = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -g3 -std=c++98 -I $(INCLUDE_DIR)

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = \
	AForm.cpp\
	Bureaucrat.cpp\
	main.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

MANDATORY_SRCS = $(SRC)

PMANDATORY =  $(addprefix , $(MANDATORY_SRCS))
OBJS = $(PMANDATORY:$(SRC_DIR)%.cpp=$(OBJ_DIR)/%.o)


all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re