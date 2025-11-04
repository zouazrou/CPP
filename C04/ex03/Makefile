 CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = exe

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	
fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re