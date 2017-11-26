NAME = run_test

GCC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wextra -Wall -Werror

SRC_DIR = src
SRC_TEST_DIR = 4tests

SRC =	main.c
SRC_TEST =	00_launcher.c 01_basic_test.c 02_segv_test.c 03_buse_test.c \
		04_ko_test.c

OBJ_DIR = obj

OBJ = $(SRC:%.c=obj/%.o)
OBJ_TEST = $(SRC_TEST:%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_TEST)
	$(GCC) -o $@ $(OBJ) $(OBJ_TEST) ../libft.a ../libftasm.a ../libftprintf.a ../libunit.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I ../libft/includes

$(OBJ_DIR)/%.o: $(SRC_TEST_DIR)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I ../libft/includes

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all obj clean fclean re project
