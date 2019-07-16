CPP_FILES=./lib/*.cpp ./lib/Math/*.h -L. -lavg
INCLUDE=-I./

test:
	g++ $(INCLUDE) -o avgLib ./src/main.cpp -std=c++17 $(CPP_FILES)
	./avgLib

lib_static:
	g++ $(INCLUDE) -c -std=c++17 $(CPP_FILES) -fpic