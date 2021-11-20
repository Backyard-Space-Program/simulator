CC = gcc
CXX = g++

CC_ARGS = -c -Wall -Wextra -std=gnu99
CXX_ARGS = -c -Wall -Wextra -std=c++17

BUILD_DIR = output
SRC_DIR = source

C_FILES = $(wildcard $(SRC_DIR)/*.c)
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)

OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=output/%_c.o) $(CXX_FILES:$(SRC_DIR)/%.cpp=output/%_cpp.o)

TARGET = simulator

.PHONY: clean

all: $(TARGET)

$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
	$(CC) $(CC_ARGS) $< -o $@

$(BUILD_DIR)/%_cpp.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_ARGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(LIBS) $(OBJ_FILES)

clean:
	rm -r output/* $(TARGET)
