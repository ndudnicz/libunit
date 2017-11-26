NAME = run_test

GCC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wextra -Wall -Werror

SRC_DIR = .
SRC_DIR_BZERO = bzero
SRC_DIR_ISALNUM = isalnum
SRC_DIR_ISALPHA = isalpha
SRC_DIR_ISDIGIT = isdigit
SRC_DIR_ATOI = atoi

OBJ_DIR = obj

SRC =	main.c
SRC_BZERO = 00_launcher_bzero.c 01_basic_test_bzero.c
SRC_ISALNUM =	00_launcher_isalnum.c 01_basic_test_isalnum.c 02_basic_test_isalnum.c \
				03_basic_test_isalnum.c 04_basic_test_isalnum.c 05_basic_test_isalnum.c \
				06_basic_test_isalnum.c 07_basic_test_isalnum.c 08_basic_test_isalnum.c \
				09_basic_test_isalnum.c 10_basic_test_isalnum.c 11_basic_test_isalnum.c
SRC_ISALPHA =	00_launcher_isalpha.c 01_basic_test_isalpha.c 02_basic_test_isalpha.c \
				03_basic_test_isalpha.c 04_basic_test_isalpha.c 05_basic_test_isalpha.c \
				06_basic_test_isalpha.c 07_basic_test_isalpha.c 08_basic_test_isalpha.c
SRC_ISDIGIT =	00_launcher_isdigit.c 01_basic_test_isdigit.c 02_basic_test_isdigit.c \
				03_basic_test_isdigit.c 04_basic_test_isdigit.c
SRC_ATOI =	00_launcher_atoi.c 01_basic_test_atoi.c 02_basic_test_atoi.c \
			03_upper_bound_test_atoi.c 04_lower_bound_test_atoi.c 05_basic_test_atoi.c

OBJ = $(SRC:%.c=obj/%.o)
OBJ_BZERO = $(SRC_BZERO:%.c=obj/%.o)
OBJ_ISALNUM = $(SRC_ISALNUM:%.c=obj/%.o)
OBJ_ISALPHA = $(SRC_ISALPHA:%.c=obj/%.o)
OBJ_ISDIGIT = $(SRC_ISDIGIT:%.c=obj/%.o)
OBJ_ATOI = $(SRC_ATOI:%.c=obj/%.o)

all: proj $(NAME)

$(NAME): $(OBJ) $(OBJ_BZERO) $(OBJ_ISALNUM) $(OBJ_ISALPHA) $(OBJ_ISDIGIT) $(OBJ_ATOI)
	$(GCC) -o $@ $(OBJ) $(OBJ_BZERO) $(OBJ_ISALNUM) $(OBJ_ISALPHA) $(OBJ_ISDIGIT) $(OBJ_ATOI) ../libft.a ../libftprintf.a ../libunit.a project/libfts.a

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_BZERO)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I bzero -I ../libft/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_ISALNUM)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I isalnum -I ../libft/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_ISALPHA)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I isalpha -I ../libft/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_ISDIGIT)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I isdigit -I ../libft/includes -I project/includes

$(OBJ_DIR)/%.o: $(SRC_DIR_ATOI)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I . -I ../framework/includes -I atoi -I ../libft/includes -I project/includes

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
