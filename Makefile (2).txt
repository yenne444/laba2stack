# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -L. -lStackTest  # Добавляем путь к библиотеке и саму библиотеку

# Целевые исполняемые файлы
TARGET = stack_demo
TEST_TARGET = stack_test

# Исходные файлы
SRC_DIR = master
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Stack.cpp $(SRC_DIR)/ListStack.cpp $(SRC_DIR)/VectorStack.cpp
TEST_SRC = $(SRC_DIR)/Stack.cpp  # Файл с тестами
OBJS = $(SRCS:.cpp=.o)
TEST_OBJ = $(TEST_SRC:.cpp=.o)
HEADERS = IStackImplementation.h ListStack.h VectorStack.h Stack.h

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(TEST_TARGET): $(TEST_OBJ) $(filter-out $(SRC_DIR)/main.o, $(OBJS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJS) $(TEST_OBJ)