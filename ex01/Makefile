CC = g++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g\
		# -I/usr/include/c++/11\
		# -I/usr/include/c++/10\
		# -I/usr/include/x86_64-linux-gnu/c++/11\


SRC = main.cpp PhoneBook.cpp

OBJ = $(SRC:.cpp=.o)

NAME = PhoneBook

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
