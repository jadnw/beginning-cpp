CXX = clang++
CXXFLAGS = -stdlib=libc++ -std=c++17 -g

all: main.o
	$(CXX) $(CXXFLAGS) -o main.o main.cpp && ./main.o

build: main.o
	$(CXX) $(CXXFLAGS) -o main.o main.cpp

run: main.o
	./main.o
