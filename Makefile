PROJECT_NAME=AvgLib
CPP_COMPILER=g++
CPP_FLAGS=-std=c++2a 
CPP_DEBUG_FLAGS:=${CPP_FLAGS} -DDEBUG -ggdb -O0 -g3 -DMALLOC_CHECK_=2

SOURCE=$(wildcard ./src/*.cpp) $(wildcard ./src/Math/*.cpp) $(wildcard ./src/Random/*.cpp) $(wildcard ./src/Terminal/*.cpp)
INCLUDE=$(wildcard ./include/avg/*.h) $(wildcard ./include/avg/Math/*.h) $(wildcard ./include/avg/Random/*.h) $(wildcard ./src/Terminal/*.h)

DIR=debug

OBJ=${foreach file, ${SOURCE:.cpp=.o}, $(subst ./src/,,${file})}
RELEASE_OBJ=${foreach file, ${SOURCE:.cpp=.o}, $(subst ./src/,./obj/release/,${file})}
DEBUG_OBJ=${foreach file, ${SOURCE:.cpp=.o}, $(subst ./src/,./obj/debug/,${file})}

# Main targets
.PHONY: debug
debug: ./build/debug/lib${PROJECT_NAME}.a

.PHONY: release
release: ./build/release/lib${PROJECT_NAME}.a

./build/debug/lib${PROJECT_NAME}.a: ${DEBUG_OBJ}
	@mkdir -p build
	@mkdir -p $(dir $@)
	@ar rvs ./build/debug/lib${PROJECT_NAME}.a $^
./build/release/lib${PROJECT_NAME}.a: ${RELEASE_OBJ}
	@mkdir -p build
	@mkdir -p $(dir $@)
	@ar rvs ./build/release/lib${PROJECT_NAME}.a $^

lib${PROJECT_NAME}.a: ${OBJ}
	@ar rvs lib${PROJECT_NAME}.a $^

.PHONY: test
test: ${OBJ} main.cpp
	@${CPP_COMPILER} ${CPP_FLAGS} -O0 -g3 -ggdb -DDEBUG -o $@ $^ -I./include/

${DEBUG_OBJ} : ./obj/debug/%.o : ./src/%.cpp ${INCLUDE}
	@mkdir -p $(dir $@)
	@${CPP_COMPILER} ${CPP_DEBUG_FLAGS} -c -o $@ $< -I./include/
${RELEASE_OBJ} : ./obj/release/%.o : ./src/%.cpp ${INCLUDE}
	@mkdir -p $(dir $@)
	@${CPP_COMPILER} ${CPP_FLAGS} -c -o $@ $< -I./include/

.PHONY: clean
clean:
	@rm -f ./build/release/lib${PROJECT_NAME}.a
	@rm -f ./build/debug/lib${PROJECT_NAME}.a
	@rm -r ./build
	@rm -f ${OBJ}
	@rm -f -r ./obj
	@echo Cleaned up successfully!