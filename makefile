CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o getInt.o  Ant.o Board.o

SRCS =  main.cpp menu.cpp getInt.cpp  Ant.o Board.cpp

HEADERS = menu.hpp getInt.hpp Ant.hpp Board.hpp

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o main

clean:
	rm main