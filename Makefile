CC		=	g++
CFLAGS	=	-Wall -Wextra -Werror
SDLFLAG	=	-lSDL2_image -g `sdl2-config --cflags --libs`
SRC_DIR	=	srcs
OBJ_DIR	=	build
INCLUDE	=	include
SRCS	=	$(wildcard $(SRC_DIR)/*.cpp)
OBJ		=	$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))
BIN		=	emulator.bin

ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
      -nrRf $(firstword $(MAKEFILE_LIST)) \
      ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = echo "`expr "   [\`expr $C '*' 100 / $T\`" : '.*\(....\)$$'`%]"
endif

all:	$(BIN)
	@$(ECHO) All Done !

$(BIN):	$(OBJ)
	@$(ECHO) Linking $@
	$(CC) -o $(BIN) $(CFLAGS) main.cpp $(OBJ) $(SDLFLAG) -I $(INCLUDE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(ECHO) Compiling $@
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE)

clean:	$(BIN)
	@$(ECHO) Clean done !
	rm -rf $(OBJ_DIR)/*.o

fclean: clean
	@$(ECHO) FClean Done !
	rm -rf $(BIN)

re:
	$(MAKE) fclean
	$(MAKE) $(BIN)

.PHONY: clean fclean re all
.SILENT:
