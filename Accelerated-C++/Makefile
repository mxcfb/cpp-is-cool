# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g -I$(INC_DIR)
INC_DIR = include
SRC_DIR = src
INC_FILES = $(addprefix $(INC_DIR)/,Core.h Grad.h grade.h Student_info.h median.h Vec.h algorithm.h) # $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(addprefix $(SRC_DIR)/,main.cpp Core.cpp Grad.cpp grade.cpp Student_info.cpp) # $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

# ****************************************************
# Targets needed to bring the executable up to date

main: $(OBJ_FILES)
	@echo Header files: $(INC_FILES)
	@echo Source files: $(SRC_FILES)
	@echo Object files: $(OBJ_FILES)
	@echo Building the final executable...
	$(CC) $(CFLAGS) $^ -o $@

# Updated Makerules

$(OBJ_FILES): %.o: %.cpp $(INC_FILES)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -f main $(SRC_DIR)/*.o *output.txt
