NAME = phonebook

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -g3 -std=c++98

FILENAMES = PhoneBook Contact main
SOURCES = $(addsuffix .cpp, $(FILENAMES))
OBJECTS = $(addsuffix .o, $(FILENAMES))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CPP) $(CPP_FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $(CPP_FLAGS) $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
