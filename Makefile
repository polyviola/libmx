CC = clang
NAME = test.c
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LFLAGS = -ILibmx/inc Libmx/libmx.a
DFLAGS = -g -fsanitize=address

all:
	@$(CC) $(CFLAGS) $(LFLAGS) $(NAME)

dbg:
	@$(CC) $(CFLAGS) $(DFLAGS) $(LFLAGS) $(NAME)

uninstall:
	@rm -f a.out

#cd Libmx && make && cd .. && make && ./a.out