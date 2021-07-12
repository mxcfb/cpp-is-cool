# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g -I$(INC_DIR)
INC_DIR = include
SRC_DIR = src
INC_FILES = $(addprefix $(INC_DIR)/,Core.h Grad.h grade.h Student_info.h median.h Vec.h algorithm.h)
SRC_FILES = $(addprefix $(SRC_DIR)/,$(OBJ_FILES:.o=.cpp))
OBJ_FILES = main.o Core.o Grad.o grade.o Student_info.o

# ****************************************************
# Targets needed to bring the executable up to date

main: $(OBJ_FILES)
	@echo Header files: $(INC_FILES)
	@echo Source files: $(SRC_FILES)
	@echo Building the final executable...
	$(CC) $(CFLAGS) -o $@ $^

# Updated Makerules

$(OBJ_FILES): %.o: $(SRC_DIR)/%.cpp $(INC_FILES)
	$(CC) $(CFLAGS) -c $<

.PHONY: clean

clean:
	rm -f main *.o *output.txt $(SRC_DIR)/*.o
