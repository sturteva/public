CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time

OBJS = Utility.o Menus.o Project3Main.o Creature.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o Fight.o

SRCS =  Menus.cpp Utility.cpp Project3Main.cpp Creature.cpp Vampire.cpp Barbarian.cpp Blue_Men.cpp Medusa.cpp Harry_Potter.cpp Fight.cpp

HEADERS = Utility.hpp Menus.hpp Creature.hpp Vampire.hpp Barbarian.hpp Blue_Men.hpp Medusa.hpp Harry_Potter.hpp Fight.hpp

#target: dependencies
#	rule to build
#
#
	
output: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o output 

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c   $(@:.o=.cpp)

clean:
	rm *.o output 
