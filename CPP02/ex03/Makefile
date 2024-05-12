# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 11:36:07 by albartol          #+#    #+#              #
#    Updated: 2024/05/12 00:01:11 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := main Fixed Point bsp

SRCS := $(addsuffix .cpp, $(SOURCES))

CPP := c++

CPP_FLAGS := -Wall -Wextra -Werror -std=c++98
# CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb

NAME := bsp

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
