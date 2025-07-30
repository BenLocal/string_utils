.SUFFIXES: .cpp .o

CXX = clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# 目标文件
OBJS = main.o

# 可执行文件
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run