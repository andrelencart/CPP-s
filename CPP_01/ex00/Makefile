
NAME=brainz
CXX=c++
CXXFLAGS= -Wall -Wextra -Werror -g -std=c++98
SRC_DIR= Src
OBJ_DIR= Obj

SRC_FILES= main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re