# Compiler. You can change
CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall

# Dircectory with project
SRC_DIR			=	src

# Directory for objective files
OBJ_DIR			=	obj

LIB_PRINTF		=	ft_printf/libftprintf.a

# ------------------------------- SERVER --------------------------------
SERVER			=	server
SRC_SERVER		=	$(shell find ${SRC_DIR}/server -type f -name "*.c" | cut -b 5-)
OBJ_SERVER		=	$(addprefix $(OBJ_DIR)/,$(SRC_SERVER:c=o))
HDR_SERVER		=	src/server/server.h

# ------------------------------- CLIENT --------------------------------
CLIENT			=	client
SRC_CLIENT		=	$(shell find ${SRC_DIR}/client -type f -name "*.c" | cut -b 5-)
OBJ_CLIENT		=	
HDR_CLIENT		=	src/client/client.h

# ----------------------------------------------------------------------
all:	$(OBJ_DIR)
	$(MAKE) -C ft_printf
	$(MAKE) -j $(SERVER)

$(OBJ_DIR):
	@mkdir -p $@/server
	@mkdir -p $@/client

# ------------------------- Compile program Server --------------------
$(SERVER):	$(OBJ_SERVER) $(HDR_SERVER)
	$(CC) $(OBJ_SERVER) $(HDR_SERVER) $(LIB_PRINTF) -o $@

# ------------------------- Compile program Client --------------------
$(ClIENT):	$(OBJ_CLIENT) $(HDR_CLIENT)
	$(CC) $(OBJ_CLIENT) $(HDR_CLIENT) $(LIB_PRINTF) -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	echo $(OBJ_SERVER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	rm -rf $(OBJ_DIR)/server
	rm -rf $(OBJ_DIR)/client

fclean:	clean
	$(MAKE) -C ft_printf fclean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all
