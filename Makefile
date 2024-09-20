NAME = Timer
CC = cc
CFLAGS = -Wall -Wextra -Werror
READ = -lreadline

SRC = ./Src/main.c
OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(CFLAGS) $(OBJ) $(READ) -o $(NAME)
 
fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all