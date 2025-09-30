SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

NAME = dynamiccast
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC_FILES =\
	main.cpp\
	Base.cpp\

INC_FILES =\
	A.hpp\
	Base.hpp\
	B.hpp\
	C.hpp\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
INCS = $(addprefix $(INCLUDE_DIR)/, $(INC_FILES))

OBJS = $(SRCS:.cpp=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCS) | $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re