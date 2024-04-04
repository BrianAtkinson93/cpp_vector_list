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
all: build

# Rule to build the executable
build: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# # Build and run tests
# test:
#	$(CC) $(CFLAGS) test_cases.cpp -o test_runner
# 	./test_runner

# Clean rule
clean:
	rm -f $(OUT)
