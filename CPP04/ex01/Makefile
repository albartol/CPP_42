# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 10:45:18 by albartol          #+#    #+#              #
#    Updated: 2024/05/13 17:35:29 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP := c++

CPPFLAGS := -Wall -Wextra -Werror -Wshadow -std=c++98

SOURCE := main Animal Dog Cat WrongAnimal WrongCat Brain

SRCS := $(addsuffix .cpp, $(SOURCE))

OBJS := $(SRCS:.cpp=.o)

NAME := fire


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
