SERVER_NAME = server
# CLIENT_NAME = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS = main.c

# BONUS = 

OBJS = $(SERVER_SRCS:.c=.o)
# BONUS_OBJS = $(BONUS:.c=.o)
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(SERVER_NAME)

$(LIBFT):
	make -C libft

$(SERVER_NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(SERVER_NAME)

# $(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
# 	$(CC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

# bonus: $(BONUS_NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(SERVER_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus