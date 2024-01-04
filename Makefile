all: compile link

compile:
	g++ -Isrc/include -c Board.cpp main.cpp

link:
	g++ main.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system
	