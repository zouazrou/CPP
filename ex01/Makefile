CC = c++

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

HDR = header.hpp Contact.hpp PhoneBook.hpp

NAME = PhoneBook

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# $(OBJ) : $(SRC) $(HDR)
# 	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
