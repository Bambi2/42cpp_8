NAME = find

CLASSES = 

SRCS = $(addsuffix .cpp, $(CLASSES)) main.cpp 

OBJS = $(SRCS:%.cpp=%.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADERS = $(addsuffix .hpp, $(CLASSES)) easyfind.hpp

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Makefile $(HEADERS)
	g++ $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
