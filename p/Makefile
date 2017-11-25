NAME = libftprintf.a

SRCS = srcs/

TOOL = srcs/tool/

TREAT = srcs/treat/

VALID = srcs/valid/

SRC = 	$(SRCS)ft_printf.c \
		$(TOOL)error.c \
		$(TOOL)ft_atoi.c \
		$(TOOL)ft_isdigit.c \
		$(TOOL)ft_isprint.c \
		$(TOOL)ft_long_numberlen.c \
		$(TOOL)ft_memset.c \
		$(TOOL)ft_putchar.c \
		$(TOOL)ft_putnchar.c \
		$(TOOL)ft_putwchar.c \
		$(TOOL)ft_putnstr.c \
		$(TOOL)ft_putstr.c \
		$(TOOL)ft_strchr.c \
		$(TOOL)ft_strdup.c \
		$(TOOL)ft_strlen.c \
		$(TOOL)ft_wstrlen.c \
		$(TOOL)ft_putnwstr.c \
		$(TOOL)get_flag.c \
		$(TOOL)init.c \
		$(TOOL)putbase_ll.c \
		$(TOOL)putbase_zj.c \
		$(TOOL)ft_strdupchr.c \
		$(TOOL)ft_strlenchr.c \
		$(TOOL)ft_strcmp.c \
		$(TREAT)switch.c \
		$(TREAT)treat_base.c \
		$(TREAT)treat_char.c \
		$(TREAT)treat_wchar.c \
		$(TREAT)treat_hexa.c \
		$(TREAT)treat_int.c \
		$(TREAT)treat_octal.c \
		$(TREAT)treat_pointer.c \
		$(TREAT)treat_str.c \
		$(TREAT)treat_unsigned.c \
		$(TREAT)treat_wstr.c \
		$(TREAT)treat_color.c \
		$(VALID)valid_flags.c \
		$(VALID)valid_format.c \
		$(VALID)valid_wstr.c \

OBJ = 	ft_printf.o \
		error.o \
		ft_atoi.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_long_numberlen.o \
		ft_memset.o \
		ft_putchar.o \
		ft_putwchar.o \
		ft_putnchar.o \
		ft_putnstr.o \
		ft_putstr.o \
		ft_putnwstr.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_wstrlen.o \
		get_flag.o \
		init.o \
		putbase_ll.o \
		putbase_zj.o \
		ft_strdupchr.o \
		ft_strlenchr.o \
		ft_strcmp.o \
		switch.o \
		treat_base.o \
		treat_char.o \
		treat_wchar.o \
		treat_hexa.o \
		treat_int.o \
		treat_octal.o \
		treat_pointer.o \
		treat_str.o \
		treat_unsigned.o \
		treat_wstr.o \
		treat_color.o \
		valid_flags.o \
		valid_format.o \
		valid_wstr.o \

CPP = gcc

FLAGS = -Werror -Wextra -Wall

all: $(NAME)
	@ln -sf ft_printf/libftprintf.a ..

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CPP) -c $(FLAGS) $(SRC) -I includes

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: clean fclean all
