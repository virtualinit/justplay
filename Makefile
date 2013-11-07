all: justplay

justplay: main.o match.o innings.o tools.o test.o
	g++ main.o match.o innings.o tools.o test.o -o justplay

main.o: main.cpp
	g++ -c main.cpp

match.o: match.cpp
	g++ -c match.cpp

innings.o: innings.cpp
	g++ -c innings.cpp

tools.o: tools.cpp
	g++ -c tools.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf *o justplay

