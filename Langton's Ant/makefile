CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time

OBJS =  Ant.o Project1Main.o 

SRCS =  Ant.cpp Utilities.cpp Menus.cpp Project1Main.cpp

HEADERS = Ant.hpp

#target: dependencies
#	rule to build

#	
Project1: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o Project1

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

clean:
	rm *.o Project1
