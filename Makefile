CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -pedantic
VALGRIND = valgrind --leak-check=full --track-origins=yes

SRC = Main.cpp Demo.cpp Test.cpp 
HEADERS = MyContainer.hpp AscendingOrder.hpp DescendingOrder.hpp ReverseOrder.hpp SideCrossOrder.hpp MiddleOutOrder.hpp Order.hpp

TARGET = main_exec
TEST_TARGET = test_exec
DEMO_TARGET = demo_exec

all: $(TARGET) $(DEMO_TARGET) $(TEST_TARGET)

$(TARGET): Main.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) Main.cpp

$(DEMO_TARGET): Demo.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) Demo.cpp

$(TEST_TARGET): Test.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) Test.cpp

demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)
	
valgrind: $(TARGET) $(TEST_TARGET)
	$(VALGRIND) ./$(TARGET)
	$(VALGRIND) ./$(TEST_TARGET)

Main: Main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) Main.cpp

clean:
	rm -f $(TARGET) $(TEST_TARGET) $(DEMO_TARGET) *.o
