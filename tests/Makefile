NAME = run_test

GCC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wextra -Wall -Werror

SRC_DIR = src

OBJ_DIR = obj

SRC =	main.c 00_launcher.c 01_basic_test.c 02_segv_test.c 03_buse_test.c \
		04_ko_test.c

OBJ = $(SRC:%.c=obj/%.o)

all: lib $(NAME)

$(NAME): $(OBJ)
	$(GCC) -o $@ $(OBJ) ../libft.a ../libftasm.a ../libftprintf.a ../libunit.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I ../libft/includes

lib:
	make -s -C ..

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME)

.PHONY: all obj clean fclean re project
