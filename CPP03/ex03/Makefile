# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 14:06:00 by albartol          #+#    #+#              #
#    Updated: 2024/05/12 21:23:58 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP := c++

CPPFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE := main ClapTrap ScavTrap FragTrap DiamondTrap

SRCS := $(addsuffix .cpp, $(SOURCE))

OBJS := $(SRCS:.cpp=.o)

NAME := diamond_trap


all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $^ -o $@

.o: .cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
