#Makefile for hw3.  I’m testing to see if being on my mac changes anything.

homework: main.o Account.o Bank.o Depositor.o Name.o
	g++ -o homework main.o Account.o Bank.o Depositor.o Name.o

Account.o: Account.cpp Account.h
	g++ -c Account.cpp

Bank.o: Bank.cpp Bank.h
	g++ -c Bank.cpp

Depositor.o: Depositor.cpp Depositor.h
	g++ -c Depositor.cpp

Name.o: Name.cpp Name.h
	g++ -c Name.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: rm ./*.o