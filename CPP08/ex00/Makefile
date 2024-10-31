# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/31 16:58:00 by albartol          #+#    #+#              #
#    Updated: 2024/10/31 16:58:15 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CPP := c++

CPPFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE := main

SRCS := $(addsuffix .cpp, $(SOURCE))

OBJS := $(SRCS:%.cpp=%.o)

NAME := easyfind


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
