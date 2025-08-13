CC := gcc

CFLAGS := -std=c99 -Wall -O3

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS = src/timing
OBJ := $(SRCS:%=$(BUILD_DIR)/%.o)


$(BUILD_DIR)/timer: $(OBJ)
	$(CC) -s -shared -o $@.dll $(OBJ) -I.$(SRC_DIRS)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ -D TIMER_EXPORTS

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
