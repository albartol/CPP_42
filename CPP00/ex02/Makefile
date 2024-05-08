# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 14:49:08 by albartol          #+#    #+#              #
#    Updated: 2024/05/08 17:48:32 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := tests Account

SRCS := $(addsuffix .cpp, $(SOURCES))

CPP := g++

# CPP_FLAGS := -Wall -Wextra -Werror -std=c++98
CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb

NAME := my_account

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

test: re
	./$(NAME) > new_test.log
	diff new_test.log 19920104_091532.log

.PHONY: all clean fclean re test
