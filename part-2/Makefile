# Compiler settings
CXX = g++
CXXFLAGS = -g -Wall -Wextra -std=c++11

# File names
TARGET = banking-system
SOURCES = main.cpp bank.cpp
HEADERS = types.h
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Pattern rule for object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJECTS) core

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug with GDB
debug: $(TARGET)
	gdb ./$(TARGET)

# Log a debug section
debug-log:
	script -c "pwd; bash" -B part2.log

.PHONY: all clean run debug
