
NAME=Account
CPP=c++
CPPF= -Wall -Wextra -Werror -g -std=c++98
OBJ_DIR= Obj
# SRC_DIR= Src

SRC_FILES= Account.cpp tests.cpp

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
# SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ)
	$(CPP) $(CPPF) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CPP) $(CPPF) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re