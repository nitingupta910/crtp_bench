CXX ?= g++
CXXFLAGS=-O3 -std=c++11

all:
	$(CXX) dynamic.cpp $(CXXFLAGS) -o dynamic
	$(CXX) crtp.cpp $(CXXFLAGS) -o crtp
	$(CXX) direct.cpp $(CXXFLAGS) -o direct
clean:
	rm -rf crtp dynamic direct
run: all
	time ./dynamic
	time ./crtp
	time ./direct

