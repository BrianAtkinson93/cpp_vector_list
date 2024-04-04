# Created by Brian Atkinson

# Define Compiler
CC = g++

# Define Compiler Flags
CFLAGS = -std=c++11

# Define the source file
SRC = main.cpp

# Define the output executable
OUT = vector_list

# The first rule is the default when make is called without args
all: build run

# Rule to build the executable
build: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Rule to run
run:
	./$(OUT)

# Clean rule
clean:
	rm -f $(OUT)
