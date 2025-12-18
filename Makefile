SERVER_NAME = server
CLIENT_NAME = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
LIBFT = libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	make -C libft

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_NAME)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus