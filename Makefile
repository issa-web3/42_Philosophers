# Executable
NAME = philo

# Compilation
CC = cc
COMPL_FLAGS = -Wall -Wextra -Werror
LINK_FLAGS =  

COMPILE = $(CC) $(COMPL_FLAGS)
LINK = $(CC) $(LINK_FLAGS)


# obj dirs
OBJ_DIR = obj
OBJ_DIRS = $(OBJ_DIR)/simulation

# INC
INC = philo.h structs.h

# SRC
SRC = main.c mutex_safe.c parsing.c time_utils.c \
	simulation/monitoring.c simulation/routine.c simulation/routine_func.c \
	simulation/start_simulation.c

# OBJ
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	@$(LINK) $(OBJ) -o $@
	@echo "[CREATING the legendary executable $@...]"

$(OBJ_DIRS):
	@mkdir -p $(OBJ_DIRS)
	@echo "[CREATING object directories...]"

$(OBJ_DIR)/%.o: %.c $(INC) | $(OBJ_DIRS)
	@$(COMPILE) -c $< -o $@
	@echo "[COMPILING $<...]"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[CLEANING object files...]"

fclean: clean
	@rm -f $(NAME)
	@echo "[CLEANING the executable...]"

re: fclean all
