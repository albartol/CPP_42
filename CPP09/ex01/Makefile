# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/09 17:08:08 by albartol          #+#    #+#              #
#    Updated: 2024/11/09 20:08:16 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP := c++

CPPFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE := main RPN

SRCS := $(addsuffix .cpp, $(SOURCE))

OBJS := $(SRCS:%.cpp=%.o)

NAME := RPN

INCLUDE := RPN.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp $(INCLUDE)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
