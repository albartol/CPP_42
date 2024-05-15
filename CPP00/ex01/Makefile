# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 17:57:34 by albartol          #+#    #+#              #
#    Updated: 2024/05/15 15:52:11 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := main Contact PhoneBook utils

SRC_DIR := src

SRCS := $(addsuffix .cpp, $(addprefix $(SRC_DIR)/, $(SOURCES)))

INCLUDE := -I include

CPP := c++

# CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 $(INCLUDE)
CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb $(INCLUDE)

NAME := phonebook

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
