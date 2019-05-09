CPP_FILES=./lib/*.cpp

test:
	g++ -o avgLib ./src/main.cpp -std=c++17 $(CPP_FILES)
	./avgLib

lib:
	g++ -c -o avgLib.o -std=c++17 $(CPP_FILES)