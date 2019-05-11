CPP_FILES=./lib/*.cpp -L. -lavg
INCLUDE=-I./

test:
	g++ $(INCLUDE) -o avgLib ./src/main.cpp -std=c++17 $(CPP_FILES)
	./avgLib

compile:
	g++ $(INCLUDE) -c -std=c++17 $(CPP_FILES) -fpic