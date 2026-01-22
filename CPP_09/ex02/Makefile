NAME=PmergeMe
CPP=c++
CPPF= -Wall -Wextra -Werror -g -std=c++98
OBJ_DIR= Obj
SRC_DIR= Src

SRC_FILES= main.cpp PmergeMe.cpp

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ)
	@echo "$(YELLOW)Compiling$ Executable ...$(RESET)"
	@$(CPP) $(CPPF) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) Created successfully!!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CPP) $(CPPF) -c $< -o $@

clean:
	@echo "$(RED)Cleaning object files ...$(RESET)"
	@echo "$(RED)Deleting executable ...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(NAME) Deleted successfully.!!$(RESET)"
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re

