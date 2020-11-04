CC = gcc
NAME = BSQ
FLAG = -Wall -Werror -Wextra
SRC = *.c
OUTS = *.o

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) $(SRC) -o $(NAME)

clean:
	@rm -f $(OUTS)
