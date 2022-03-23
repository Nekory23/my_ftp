##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

## Var def ##
SHELL		=	/bin/sh
CC			=	gcc
CPP			=	g++
RM			=	rm -f
#############

## Sources ##
MAIN		=	src/main.c

BIN_SRC		=	src/start.c				\
				src/init_server.c		\
				src/connection.c		\
				src/manage_client.c		\
				src/gest_command.c		\
				src/exec_cmd.c			\
				src/split.c				\
				src/commands/cdup.c		\
				src/commands/cwd.c		\
				src/commands/dele.c		\
				src/commands/help.c		\
				src/commands/list.c		\
				src/commands/noop.c		\
				src/commands/pass.c		\
				src/commands/pasv.c		\
				src/commands/port.c		\
				src/commands/pwd.c		\
				src/commands/quit.c		\
				src/commands/retr.c		\
				src/commands/stor.c		\
				src/commands/user.c		\

TEST_SRC	=	tests/test_display_help.c	\

INC			=	-I./include/
#############

##	Obj	   ##
MAIN_OBJ	=	$(MAIN:.c=.o)
SRC_OBJ		=	$(BIN_SRC:.c=.o)
TEST_OBJ	=	$(TEST_SRC:.c=.o)
#############

##	Flags  ##
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(INC)
LDFLAGS		=
#############

##	Names  ##
BIN			=   myftp
TEST_BIN	=	unit_tests
#############

##	Rules  ##
all:	$(MAIN_OBJ) $(SRC_OBJ)
	@$(CC) -o $(BIN) $(MAIN_OBJ) $(SRC_OBJ) $(CFLAGS) $(CPPFLAGS)
	@printf "[\033[0;36mbuilt\033[0m] % 32s\n" $(BIN) | tr ' ' '.'

# Debug
debug:	fclean
debug:	CFLAGS += -g3 -DDEBUG
debug:	all

# Unit Test
tests_run:	fclean
tests_run:	CFLAGS += --coverage
tests_run:	LDFLAGS += -lcriterion -DUNIT_TEST
tests_run:	$(SRC_OBJ) $(TEST_OBJ)
	$(CC) -o $(TEST_BIN) $(BIN_SRC) $(TEST_SRC) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)
	./$(TEST_BIN)

# Coverage
coverage:
	gcovr -b --exclude-directories tests
	gcovr -r . --exclude-directories tests

# Clear
clean:
	@$(RM) $(MAIN_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(MAIN_OBJ) | tr ' ' '.'
	@$(RM) $(SRC_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(SRC_OBJ) | tr ' ' '.'
	@$(RM) $(TEST_OBJ)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_OBJ) | tr ' ' '.'

fclean: clean
	@$(RM) $(BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(BIN) | tr ' ' '.'
	@$(RM) $(TEST_BIN)
	@printf "[\033[0;31mdeleted\033[0m] % 30s\n" $(TEST_BIN) | tr ' ' '.'
	@$(RM) */*/*.gc*
	@$(RM) */*.gc*
	@$(RM) *.gc*

# re
re : fclean all

# PHONY
.PHONY: all debug tests_run coverage clean fclean re