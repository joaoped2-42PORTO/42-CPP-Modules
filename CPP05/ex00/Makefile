NAME	=	bureaucrat
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -g -std=c++98
SRC		=	main.cpp Bureaucrat.cpp
OBJ		=	$(SRC:.cpp=.o)

all: $(NAME)

$(NAME):	$(OBJ)
			@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all
