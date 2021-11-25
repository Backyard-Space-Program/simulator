CXX = g++

CXX_ARGS = -c -Wall -Wextra -std=c++17 -Istdlib
STD_ARGS = $(CXX_ARGS)

BUILD_DIR = output
SRC_DIR = source
STD_DIR = stdlib

STD_FILES = $(wildcard $(STD_DIR)/*.cpp)
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_FILES = $(STD_FILES:$(STD_DIR)/%.cpp=output/%_std.o) $(CXX_FILES:$(SRC_DIR)/%.cpp=output/%_cpp.o)

TARGET = simulator

.PHONY: clean

all: $(TARGET)

$(BUILD_DIR)/%_cpp.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_ARGS) $< -o $@

$(BUILD_DIR)/%_std.o: $(STD_DIR)/%.cpp
	$(CXX) $(STD_ARGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(OBJ_FILES)

clean:
	rm -r output/* $(TARGET)
