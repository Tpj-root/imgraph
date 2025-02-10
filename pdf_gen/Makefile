# Makefile for Cairo-based PDF grid generation

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Cairo library flags
LIBS = -lcairo

# Output binary
OUTPUT = grid_generator

# Source files
SRC = main.cpp

# Include directories
INCLUDES = -I/usr/include/cairo

# Rule to build the program
$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(OUTPUT) $(LIBS)

# Rule to clean up generated files
clean:
	rm -f $(OUTPUT)

# Phony targets
.PHONY: clean
