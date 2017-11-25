NAME = libunit.a

GCC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS =  -Wextra -Wall #-Werror

SRC_FRAMEWORK = load_test.c run_tests.c

INCLUDES_DIR_FRAMEWORK = framework/includes

SRC_DIR_FRAMEWORK = framework/src

OBJ_DIR_FRAMEWORK = framework/obj

OBJ_FRAMEWORK = $(SRC_FRAMEWORK:%.c=framework/obj/%.o)

all: lib $(NAME)

$(NAME): $(OBJ_FRAMEWORK)
	ar rc $@ $(OBJ_FRAMEWORK)

$(OBJ_DIR_FRAMEWORK)/%.o: $(SRC_DIR_FRAMEWORK)/%.c
	$(GCC) $(FLAGS) -c $< -o $@ -I $(INCLUDES_DIR_FRAMEWORK) -I libft/includes -I ft_printf

lib:
	make -s -C libft
	make -s -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	$(RM) libft.a libftasm.a $(NAME) libftprintf.a

re: clean fclean all

.PHONY: all libasm obj clean fclean re libftasm