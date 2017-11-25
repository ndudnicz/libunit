NAME = run_test

GCC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS = -g -Wextra -Wall -Werror

SRC_DIR = src

SRC_DIR_BZERO = bzero

OBJ_DIR = obj

SRC =	main.c

SRC_BZERO = 00_launcher_bzero.c 01_basic_test_bzero.c

OBJ = $(SRC:%.c=obj/%.o)

OBJ_BZERO = $(SRC_BZERO:%.c=obj/%.o)

all: lib proj $(NAME)

$(NAME): $(OBJ) $(OBJ_BZERO)
	$(GCC) -o $@ $(OBJ) $(OBJ_BZERO) ../libft.a ../libftprintf.a ../libunit.a project/libfts.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_BZERO)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I project/includes -I bzero -I ../libft/includes

lib:
	make -s -C ..

proj:
	make -C project


clean:
	make clean -C project
	$(RM) $(OBJ)

fclean: clean
	make fclean -C project
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all obj clean fclean re
