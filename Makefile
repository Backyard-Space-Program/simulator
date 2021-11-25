CXX = g++

CXX_ARGS = -c -Wall -Wextra -std=c++17
STD_ARGS = $(CXX_ARGS)

BUILD_DIR = output
SRC_DIR = source
STD_DIR = stdlib

STD_FILES = $(wildcard $(STD_DIR)/*.cpp)
CXX_FILES = $(wildcard $(SRC_DIR)/*.cpp)

STD_OBJ = $(STD_FILES:$(STD_DIR)/%.cpp=output/%_std.o)
OBJ_FILES = $(CXX_FILES:$(SRC_DIR)/%.cpp=output/%_cpp.o)

TARGET = simulator
STDLIB = stdlib.so

.PHONY: clean

all: $(TARGET)

lib: $(STDLIB)

$(BUILD_DIR)/%_cpp.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXX_ARGS) $< -o $@

$(BUILD_DIR)/%_std.o: $(STD_DIR)/%.cpp
	$(CXX) $(STD_ARGS) $< -o $@

$(TARGET): $(OBJ_FILES)
	$(CXX) -o $(TARGET) $(LIBS) $(OBJ_FILES)

$(STDLIB): $(STD_OBJ)
	$(CXX) -shared -o $(STDLIB) $(STD_OBJ)

clean:
	rm -r output/* $(TARGET)
