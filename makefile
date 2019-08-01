CPP_FILES=./lib/*.cpp ./lib/Math/*.cpp -L. -lavg
INCLUDE=-I./

test:
	g++ $(INCLUDE) -o avgLib ./main.cpp  -std=c++17 $(CPP_FILES)
	./avgLib

lib_static:
	g++ $(INCLUDE) -c -std=c++17 $(CPP_FILES) -fpic