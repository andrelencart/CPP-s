NAME=Intern
CPP=c++
CPPF= -Wall -Wextra -Werror -g -std=c++98
OBJ_DIR= Obj
SRC_DIR= Src

SRC_FILES= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ)
	@echo "\e[1;91mCompiling Ex03 ..."
	@$(CPP) $(CPPF) $(OBJ) -o $(NAME)
	@echo "\e[1;91mDONE !!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CPP) $(CPPF) -c $< -o $@

clean:
	@echo "\e[1;33mClEANING ..."
	@rm -rf $(OBJ_DIR)
	@touch home_shrubbery
	@rm home_shrubbery
	@echo "\e[1;33mDONE !!"
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re