NAME=libmygui.a
SRC = gui.cpp widget.cpp rect.cpp label.cpp base.cpp point.cpp
OBJ =$(SRC:.cpp=.o)
CXXFLAGS=-Wall -Wextra -std=c++11 -ggdb3
CXX=clang++

all: $(NAME)

$(NAME): $(OBJ)
				 ar rcs $(NAME) $(OBJ)
				 ranlib $(NAME)

d: demo

demo: $(NAME) demo.o
		  $(CXX) -o demo demo.o $(NAME) -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -f $(OBJ) demo.o

fclean: clean
	rm -f $(NAME) demo

re: fclean all

.PHONY: all clean fclean re
