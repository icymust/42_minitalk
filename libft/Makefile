NAME = libft.a
MANDATORY = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c ft_print_char.c ft_print_str.c ft_check_format.c \
	ft_print_hex.c ft_print_pointer.c ft_print_num.c ft_print_unsigned.c
	
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJ_PATH = ${MANDATORY:.c=.o}
BONUS_PATH = ${BONUS:.c=.o}

CC = cc 
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clear fclean re bonus

$(NAME): ${OBJ_PATH}
	ar rcs ${NAME} ${OBJ_PATH}
all: ${NAME}

clean: 
	${RM} ${OBJ_PATH} ${BONUS_PATH}

fclean: clean
	${RM} ${NAME}

re: fclean all

bonus: ${OBJ_PATH} ${BONUS_PATH}
	ar rcs ${NAME} ${OBJ_PATH} ${BONUS_PATH}
