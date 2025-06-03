SERVER = server
CLIENT = client

COMPILER = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I include -I libft/includes

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_PATH = src

SRC_S = $(SRC_PATH)/server.c
OBJECTS_S = $(SRC_S:%.c=%.o)

SRC_C = $(SRC_PATH)/client.c
OBJECTS_C = $(SRC_C:%.c=%.o)

all: libft $(SERVER) $(CLIENT)

libft:
	@if [ ! -f "$(LIBFT)" ]; then \
		make -s -C $(LIBFT_PATH); \
	fi

$(SERVER): $(OBJECTS_S)
	$(COMPILER) $(OBJECTS_S) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJECTS_C)
	$(COMPILER) $(OBJECTS_C) $(LIBFT) -o $(CLIENT)

%.o: %.c
	$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -r $(OBJECTS_S) $(OBJECTS_C)
	@make clean -s -C $(LIBFT_PATH)
	@echo "clean done!"

fclean: clean
	@rm -r $(SERVER) $(CLIENT)
	@make fclean -s -C $(LIBFT_PATH)
	@echo "fclean done!"

re: fclean all

.PHONY: all libft clean fclean re