.SUFFIXES: .c .o

CC = clang
CFLAGS = -std=c11 -Wall -Wextra -O2

# 目标文件
OBJS = main.o

# 可执行文件
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run