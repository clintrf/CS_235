##CFLAGS=-std=c++11 -g
##all: *.cpp
##	g++ -std=c++11 *.cpp -o lab_1
	
rpglab01: Arena.o Fighter.o Archer.o Robot.o Cleric.o main.o
	g++ -std=c++11 -o lab1 Arena.o Fighter.o Archer.o Robot.o Cleric.o main.o
	
Fighter.o: Fighter.cpp Fighter.h FighterInterface.h
	g++ -std=c++11 -c Fighter.cpp
	
Archer.o: Archer.cpp Archer.h Fighter.h FighterInterface.h
	g++ -std=c++11 -c Archer.cpp
	
Robot.o: Robot.cpp Robot.h Fighter.h FighterInterface.h
	g++ -std=c++11 -c Robot.cpp
	
Cleric.o: Cleric.cpp Cleric.h Fighter.h FighterInterface.h
	g++ -std=c++11 -c Cleric.cpp
	
Arena.o: Arena.cpp Arena.h ArenaInterface.h Fighter.h FighterInterface.h Archer.h Robot.h Cleric.h
	g++ -std=c++11 -c Arena.cpp
	
main.o: main.cpp Arena.h
		g++ -std=c++11 -c main.cpp