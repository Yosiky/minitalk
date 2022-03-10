# Compiler. You can change
CC				=	gcc
CFLAGS			=	-Wextra -Werror -Wall

# Dircectory with project
SRC_DIR			=	src

# Directory for objective files
OBJ_DIR			=	obj

# ------------------------------- SERVER --------------------------------
SERVER			=	server
SRC_SERVER		=	$(shell find ${SRC_DIR}/server -type f -name "*.c" | cut -b 5-)
OBJ_SERVER		=	$(addprefix $(OBJ_DIR)/,$(SRC_SERVER:c=o))
HDR_SERVER		=	src/server/server.h

# ------------------------------- CLIENT --------------------------------
CLIENT			=	client
SRC_CLIENT		=	$(shell find ${SRC_DIR}/client -type f -name "*.c" | cut -b 5-)
OBJ_CLIENT		=	$(addprefix $(OBJ_DIR)/,$(SRC_CLIENT:c=o))
HDR_CLIENT		=	src/client/client.h

# ----------------------------- BONUS SERVER ---------------------------
BONUS_SERVER	=	server_bon
BONUS_CLIENT	=	client_bon

SRC_BON_SERVER	=	$(shell find ${SRC_DIR}/bonus/server -type f -name "*.c" | cut -b 5-)
OBJ_BON_SERVER		=	$(addprefix $(OBJ_DIR)/bonus/,$(SRC_SERVER:c=o))

SRC_BON_CLIENT	=	$(shell find ${SRC_DIR}/bonus/client -type f -name "*.c" | cut -b 5-)
OBJ_BON_CLIENT	=	$(addprefix $(OBJ_DIR)/bonus/,$(SRC_CLIENT:c=o))

HDR_BON_SERVER	=	src/bonus/server/server_bonus.h
HDR_BON_CLIENT	=	src/bonus/client/client_bonus.h

BONUS_DIR		=	obj/bonus



# ----------------------------------------------------------------------
all:	$(OBJ_DIR)
	$(MAKE) -j $(SERVER)
	$(MAKE) -j $(CLIENT)
	
bonus: $(BONUS_DIR)
	$(MAKE) -j $(BONUS_SERVER)
	$(MAKE) -j $(BONUS_CLIENT)

$(BONUS_DIR):
	mkdir -p $(OBJ_DIR)/server
	mkdir -p $(OBJ_DIR)/client
	mkdir -p $@/server
	mkdir -p $@/client

$(OBJ_DIR):
	mkdir -p $(BONUS_DIR)/server
	mkdir -p $(BONUS_DIR)/client
	mkdir -p $@/server
	mkdir -p $@/client

# ------------------------- Compile program Server --------------------
$(SERVER):	$(OBJ_SERVER) $(HDR_SERVER)
	$(CC) $(OBJ_SERVER) -o $@

# ------------------------- Compile program Client --------------------
$(CLIENT):	$(OBJ_CLIENT) $(HDR_CLIENT)
	$(CC) $(OBJ_CLIENT) -o $@

$(BONUS_SERVER): $(OBJ_BON_SERVER) $(HDR_BON_SERVER)
	$(CC) $(OBJ_BON_SERVER) -o server

$(BONUS_CLIENT): $(OBJ_BON_CLIENT) $(HDR_BON_CLIENT)
	$(CC) $(OBJ_BON_CLIENT) -o client

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(SERVER) $(CLIENT)

re: fclean all
