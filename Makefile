NAME = expert_system

SRC = src/main.cpp \
		src/readFile.cpp

OBJ = $(SRC:.cpp=.o)

CFLAG = -Wall -Werror -Wextra

INCLUDES = -I includes/

all: $(NAME)

$(NAME):
	@g++ $(INCLUDES) -c $(SRC)
	@echo "OBJECTS CREATED"
	@/bin/mv -f *.o src
	@g++ $(CFLAG) $(INCLUDES) -o $(NAME) $(OBJ)
	@echo "PROJECT CREATED"

clean:
	@/bin/rm -f $(OBJ)
	@echo "OBJECTS CLEANED"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "ALL FILES CLEANED"

re: fclean all