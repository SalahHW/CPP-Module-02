# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 15:33:56 by sbouheni          #+#    #+#              #
#    Updated: 2023/11/28 16:37:38 by sbouheni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	fixed

CXX					=	g++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g					\

SRCS				=	source/main.cpp										\
						source/Fixed.cpp									\

HDRS				=	include/Fixed.hpp									\

OBJS				=	$(SRCS:.cpp=.o)

all					:	$(NAME)

$(NAME)				:	$(OBJS) $(HDRS)
						$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean				:
						rm -f $(OBJS)

fclean				:	clean
						rm -f $(NAME)

re					:	fclean all

.PHONY				:	all clean fclean re
