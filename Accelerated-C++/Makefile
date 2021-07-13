# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g -I$(INC_DIR)
INC_DIR = include
SRC_DIR = src

# List of all .h header files, equal to `INC_FILES = $(wildcard $(INC_DIR)/*.h)`.
INC_FILES = $(addprefix $(INC_DIR)/,Core.h Grad.h Student_info.h grade.h Vec.h algorithm.h median.h)

# List of all .cpp source files, equal to `SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)`.
SRC_FILES = $(addprefix $(SRC_DIR)/,main.cpp Core.cpp Grad.cpp Student_info.cpp grade.cpp)

# All .o object files go to src dir.
OBJ_FILES = $(SRC_FILES:%.cpp=%.o)

# GCC/Clang will create these .d files containing dependencies.
DEP_FILES = $(SRC_FILES:%.cpp=%.d)

# ****************************************************
# Targets needed to bring the executable up to date

main: $(OBJ_FILES)
	@echo Header files: $(INC_FILES)
	@echo Source files: $(SRC_FILES)
	@echo Object files: $(OBJ_FILES)
	@echo Dependency files: $(DEP_FILES)
	@echo Building the final executable...
	$(CC) $(CFLAGS) $^ -o $@

# Include all .d files.
# For example, src/main.d: `src/main.o: src/main.cpp include/Student_info.h include/Vec.h include/Core.h include/Grad.h`
# Note: All the prerequisites for the same target are merged into one.
-include $(DEP_FILES)

$(OBJ_FILES): %.o: %.cpp
	@# The -MMD flags additionally creates a .d file with the same name as the .o file.
	$(CC) $(CFLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	rm -f main $(OBJ_FILES) $(DEP_FILES) *output.txt
