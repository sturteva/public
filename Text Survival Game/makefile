CXX = g++
CXXFLAGS =  -std=c++0x
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors
CXXFLAGS +=   -g
#CXXFLAGS +=   -O3
LDFLAGS =  -lboost_date_time

OBJS = Utility.o Menus.o FinalMain.o Item.o Container.o Space.o Mountain.o Field.o Forest.o Player.o Survival_Game.o

SRCS =  Utility.cpp Menus.cpp FinalMain.cpp Item.cpp Container.cpp Space.cpp Mountain.cpp Field.cpp Forest.cpp Player.cpp Survival_Game.cpp

HEADERS = Utility.hpp Menus.hpp Item.hpp Container.hpp Space.hpp Mountain.hpp Field.hpp Forest.hpp Player.hpp Survival_Game.hpp 

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
