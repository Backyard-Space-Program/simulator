CXX = g++

CXX_ARGS = -c -Wall -Wextra -std=c++17 -Istdlib -Isource
STD_ARGS = $(CXX_ARGS)

BUILD_DIR = output
SOURCE_DIR = source
SRC_DIR = board_source
STD_DIR = stdlib

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
STD_FILES = $(wildcard $(STD_DIR)/*.cpp)
CXX_FILES = $(wildcard $(SOURCE_DIR)/*.cpp)

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.cpp=output/%_src.o) $(STD_FILES:$(STD_DIR)/%.cpp=output/%_std.o) $(CXX_FILES:$(SOURCE_DIR)/%.cpp=output/%_cpp.o)

TARGET = simulator

.PHONY: clean

all: $(TARGET)

$(BUILD_DIR)/%_src.o: $(SRC_DIR)/%.cpp
	@if [[ ! -d "output" ]]; then mkdir output; fi
	$(CXX) $(CXX_ARGS) $< -o $@

$(BUILD_DIR)/%_cpp.o: $(SOURCE_DIR)/%.cpp
	@if [[ ! -d "output" ]]; then mkdir output; fi
	$(CXX) $(CXX_ARGS) $< -o $@

$(BUILD_DIR)/%_std.o: $(STD_DIR)/%.cpp
	@if [[ ! -d "output" ]]; then mkdir output; fi
	$(CXX) $(STD_ARGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(OBJ_FILES)

clean:
	rm -r output $(TARGET)
