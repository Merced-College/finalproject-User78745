CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS =
TARGET = main
SRCS = main.cpp game.cpp Player.cpp allies.cpp enemies.cpp rooms.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = game.h Player.h allies.h enemies.h rooms.h


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: CXXFLAGS += -DDEBUG
debug: all

.PHONY: all clean run debug