CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp  

OBJ = $(SRC:.cpp=.o)

NAME = sed_is_for_losers

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
