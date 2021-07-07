# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
 
CC = g++
INCLUDE_DIR = ./include
SOURCE_DIR = ./src
CFLAGS = -Wall -g -I$(INCLUDE_DIR)
 
# ****************************************************
# Targets needed to bring the executable up to date
 
main: main.o Core.o Grad.o grade.o Student_info.o
	echo "Building..."
	$(CC) $(CFLAGS) -o main main.o Core.o Grad.o grade.o Student_info.o
 
# Dummy Makerules
 
main.o: $(SOURCE_DIR)/main.cpp $(INCLUDE_DIR)/Student_info.h $(INCLUDE_DIR)/Vec.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/main.cpp
 
Student_info.o: $(SOURCE_DIR)/Student_info.cpp $(INCLUDE_DIR)/Student_info.h $(INCLUDE_DIR)/Core.h $(INCLUDE_DIR)/Grad.h $(INCLUDE_DIR)/grade.h $(INCLUDE_DIR)/Vec.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Student_info.cpp

Core.o: $(SOURCE_DIR)/Core.cpp $(INCLUDE_DIR)/Core.h $(INCLUDE_DIR)/grade.h $(INCLUDE_DIR)/Vec.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Core.cpp

Grad.o: $(SOURCE_DIR)/Grad.cpp $(INCLUDE_DIR)/Core.h $(INCLUDE_DIR)/Grad.h $(INCLUDE_DIR)/grade.h $(INCLUDE_DIR)/Vec.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/Grad.cpp 

grade.o: $(SOURCE_DIR)/grade.cpp $(INCLUDE_DIR)/grade.h $(INCLUDE_DIR)/median.h $(INCLUDE_DIR)/Vec.h
	$(CC) $(CFLAGS) -c $(SOURCE_DIR)/grade.cpp

.PHONY: clean

clean:
	rm -f main *.o *output.txt ./src/*.o
