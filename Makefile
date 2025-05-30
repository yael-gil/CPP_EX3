CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

TARGET = coup

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
