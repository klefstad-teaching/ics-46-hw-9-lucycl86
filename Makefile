CXXFLAGS=-ggdb -std=c++20 -Wall -Wextra -Werror -Wfatal-errors -pedantic
lmain: src/ladder_main.cpp ladder.o
	g++ $(CXXFLAGS) src/ladder_main.cpp ladder.o -o lmain

dmain: src/dijkstras_main.cpp dijkstras.o
	g++ $(CXXFLAGS) src/dijkstras_main.cpp dijkstras.o -o dmain

ladder.o: src/ladder.cpp src/ladder.h
	g++ $(CXXFLAGS) -c src/ladder.cpp -o ladder.o

dijkstras.o: src/dijkstras.cpp src/dijkstras.h
	g++ $(CXXFLAGS) -c src/dijkstras.cpp -o dijkstras.o

clean:
	/bin/rm lmain dmain