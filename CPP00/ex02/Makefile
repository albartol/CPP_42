# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:49:08 by albartol          #+#    #+#              #
#    Updated: 2024/05/08 14:51:11 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := Acount

SRC_DIR := src

SRCS := $(addsuffix .cpp, $(addprefix $(SRC_DIR)/, $(SOURCES)))

CPP := g++

# CPP_FLAGS := -Wall -Wextra -Werror -std=c++98
CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb

NAME := acount

OBJS := $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPP_FLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
