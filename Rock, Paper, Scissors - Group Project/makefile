CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
LDFLAGS = -lboost_date_time
 
OBJS = Functions.o Rock.o Paper.o Scissors.o Tool.o RPSGame.o play_game.o 

SRCS = Functions.cpp Rock.cpp Paper.cpp Scissors.cpp Tool.cpp RPSGame.cpp play_game.cpp

HEADERS = Functions.hpp Rock.hpp Paper.hpp Scissors.hpp Tool.hpp RPSGame.hpp

RPSGame: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o play_game

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o play_game
