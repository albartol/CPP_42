# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albartol <albartol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 20:37:48 by albartol          #+#    #+#              #
#    Updated: 2024/10/30 14:10:28 by albartol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES := main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

SRCS := $(addsuffix .cpp, $(SOURCES))

CPP := c++

CPP_FLAGS := -Wall -Wextra -Werror -std=c++98
# CPP_FLAGS := -Wall -Wextra -Werror -std=c++98 -ggdb

NAME := forms

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
