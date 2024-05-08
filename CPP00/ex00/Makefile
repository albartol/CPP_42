# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 17:57:34 by albartol          #+#    #+#              #
#    Updated: 2024/05/06 19:25:34 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP := g++

CPPFLAGS := -Wall -Wextra -Werror -std=c++98

SRC := megaphone.cpp

OBJ := $(SRC:.cpp=.o)

NAME := megaphone

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
