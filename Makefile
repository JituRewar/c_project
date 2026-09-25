# ==============================================================================
# Makefile - C Learning & DSA Toolkit
# ==============================================================================
# This Makefile is designed to be readable and educational for first-year students.
#
# Common commands:
#   make            - Compiles both the example demonstration and unit tests
#   make test       - Compiles and runs the unit test suite
#   make run        - Compiles and runs the example demonstration
#   make clean      - Removes compiled binaries and intermediate object files
#   make help       - Displays this help menu
# ==============================================================================

CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99 -Iinclude -O2
LDFLAGS :=

# Directory structure
SRC_DIR := src
INC_DIR := include
EX_DIR  := examples
TEST_DIR:= tests
OBJ_DIR := obj
BIN_DIR := bin

# Source files and objects for toolkit library
LIB_SRCS := $(wildcard $(SRC_DIR)/*.c)
LIB_OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(LIB_SRCS))

# Targets
EXAMPLE_BIN := $(BIN_DIR)/example
TEST_BIN    := $(BIN_DIR)/test_suite

.PHONY: all clean test run help

# Default target: build both example and test binary
all: $(EXAMPLE_BIN) $(TEST_BIN)
	@echo ""
	@echo "Build complete! You can run:"
	@echo "  ./$(EXAMPLE_BIN)  (to view the demonstration)"
	@echo "  make test         (to run the test suite)"

# Compile library source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Build example demonstration executable
$(EXAMPLE_BIN): $(LIB_OBJS) $(EX_DIR)/main.c | $(BIN_DIR)
	@echo "Linking example binary $@..."
	$(CC) $(CFLAGS) $(EX_DIR)/main.c $(LIB_OBJS) -o $@ $(LDFLAGS)

# Build unit test executable
$(TEST_BIN): $(LIB_OBJS) $(TEST_DIR)/test.c | $(BIN_DIR)
	@echo "Linking test binary $@..."
	$(CC) $(CFLAGS) $(TEST_DIR)/test.c $(LIB_OBJS) -o $@ $(LDFLAGS)

# Run unit tests
test: $(TEST_BIN)
	@echo ""
	@./$(TEST_BIN)

# Run the demonstration example
run: $(EXAMPLE_BIN)
	@echo ""
	@./$(EXAMPLE_BIN)

# Ensure directory output folders exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Remove build artifacts
clean:
	@echo "Cleaning up build artifacts..."
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Clean finished."

# Help menu
help:
	@echo "C Learning & DSA Toolkit - Available Make Targets:"
	@echo "  make         - Build demonstration and test suite binaries"
	@echo "  make run     - Build and run the example demo program"
	@echo "  make test    - Build and run all automated unit tests"
	@echo "  make clean   - Remove all compiled objects and binaries"
	@echo "  make help    - Display this information"
