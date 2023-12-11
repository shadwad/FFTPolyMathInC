# Define the C compiler to use (default is gcc)
CC ?= gcc

# Define any compile-time flags (default flags include -Wall and -g)
CFLAGS ?= -Wall -g

# Define the libraries to link
LIBS = -lm

# Define the source directory
SRC_DIR = src

# Define the object directory
OBJ_DIR = obj

# Define the binary directory
BIN_DIR = bin

# Define the C source files
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Define the C object files 
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Define the executable file 
MAIN = $(BIN_DIR)/fftpolymathinc

.PHONY: all clean debug run

all: $(MAIN)
	@echo Compiled successfully!

$(MAIN): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR) *~

debug: CFLAGS += -DDEBUG -g
debug: $(MAIN)

run: $(MAIN)
	@$(MAIN)