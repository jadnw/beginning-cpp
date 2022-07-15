CXX = clang++
CXXFLAGS = -std=c++1z -g

all: main.o
	$(CXX) $(CXXFLAGS) -o main.o main.cpp && ./main.o

build: main.o
	$(CXX) $(CXXFLAGS) -o main.o main.cpp

run: main.o
	./main.o
