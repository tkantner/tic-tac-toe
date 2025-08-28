# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

# Target executable
TARGET := tictactoe

# Source files
SRCS := main.cpp player.cpp game.cpp ui.cpp

# Default rule
all: $(TARGET)

# Build the target directly from sources
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SRCS)

# Clean just removes the executable
clean:
	rm -f $(TARGET)

# Run convenience target
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run