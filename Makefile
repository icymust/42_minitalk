SERVER_NAME = server
CLIENT_NAME = client
SERVER_NAME_BONUS = server_bonus
CLIENT_NAME_BONUS = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror 

SERVER_SRCS = src/server.c
CLIENT_SRCS = src/client.c
SERVER_SRCS_BONUS = src/server_bonus.c
CLIENT_SRCS_BONUS = src/client_bonus.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

LIBFT = libft/libft.a

all: $(SERVER_NAME) $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME_BONUS): $(LIBFT) $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) $(SERVER_OBJS_BONUS) $(LIBFT) -o $(SERVER_NAME_BONUS)

$(CLIENT_NAME_BONUS): $(LIBFT) $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS_BONUS) $(LIBFT) -o $(CLIENT_NAME_BONUS)

clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	make -C libft clean

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)
	make -C libft fclean

re: fclean all

bonus: $(SERVER_NAME_BONUS) $(CLIENT_NAME_BONUS)

.PHONY: all clean fclean re bonus