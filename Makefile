NAME = SnakeGame

CC = g++
CPPFLAGS = -g -Wall -Werror -Wextra
LDFLAGS = -lglut -lGLU -lGL
RM = rm -rf

HEADER = inc/Header.hpp \
		inc/Snake.hpp \
	 	inc/Map.hpp \
		inc/Head.hpp
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.cpp,$(D_OBJ)%.o,$(SRCS))
SRCS = src/main.cpp \
		src/Snake.cpp \
		src/Map.cpp \
		src/utils.cpp \
		src/Head.cpp


#------------------------------------------------------------------------------#
#                                   RULES                                      #
#------------------------------------------------------------------------------#

all: $(NAME)
	@echo "$(OK_COLOR)BOOM 💥💥💥💥💥 $(NAME) Compiled! 💯 $(DEFAULT)"

$(NAME): $(D_OBJ) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

$(D_OBJ):
	@mkdir -p $(D_OBJ)

$(OBJS): $(D_OBJ)%.o: $(D_SRC)%.cpp $(HEADER)
	@$(CC) $(CPPFLAGS) -c $< -o $@

run: re
	@clear
	@./$(NAME)


clean:
	@$(RM) $(D_OBJ)
	@echo "$(OK_COLOR)$(NAME) Cleaned 💯 $(DEFAULT)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


#------------------------------------------------------------------------------#
#                                   COLORS                                     #
#------------------------------------------------------------------------------#

RED = \033[1;31m
YELLOW = \033[1;33m
DEFAULT = \033[0m
COM_COLOR = \033[0;34m
OBJ_COLOR = \033[0;36m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
NO_COLOR = \033[m

summary:
	valgrind --leak-check=summary --trace-children=yes --track-fds=yes ./$(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes ./$(NAME)
