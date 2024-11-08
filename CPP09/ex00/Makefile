# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 14:32:19 by albartol          #+#    #+#              #
#    Updated: 2024/11/08 16:50:54 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP := c++

CPPFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE := main BitcoinExchange

SRCS := $(addsuffix .cpp, $(SOURCE))

OBJS := $(SRCS:%.cpp=%.o)

NAME := btc

INCLUDE := BitcoinExchange.hpp

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
