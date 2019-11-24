PROJECT_NAME=AvgLib
CPP_COMPILER=g++
CPP_FLAGS=-std=c++2a

SOURCES=$(wildcard ./src/*.cpp) $(wildcard ./src/Math/*.cpp) $(wildcard ./src/Random/*.cpp)
INCLUDE=$(wildcard ./include/avg/*.h) $(wildcard ./include/avg/Math/*.h) $(wildcard ./include/avg/Random/*.h)

OBJS=${SOURCES:.cpp=.o}

lib${PROJECT_NAME}.a: ${OBJS}
	ar rvs lib${PROJECT_NAME}.a $^

${OBJS} : %.o : %.cpp ${INCLUDE}
	${CPP_COMPILER} ${CPP_FLAGS} -c -o $@ $< -I./include/

.PHONY: clean
clean:
	@rm ${OBJ}