#######################################################
#
#    Aland Sailing Robot
#    ===========================================
#    ruddercommand
#    -------------------------------------------
#
#######################################################

CC = g++
FLAGS = -Wall -pedantic -Werror -std=c++14
LIBS =

SOURCES = RudderCommand.cpp
HEADERS = RudderCommand.h
FILE = RudderCommand.o



all : $(FILE)
$(FILE) : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -c -o $(FILE)

example : $(SOURCES) $(HEADERS) example.cpp
	$(CC) $(SOURCES) example.cpp $(FLAGS) $(LIBS) -o example

metatest : $(SOURCES) $(HEADERS) $(SAILINGROBOTS_HOME)/tests/catch.hpp $(SAILINGROBOTS_HOME)/tests/testsuite/testRudderCommand.cpp
	$(CC) $(SOURCES) $(SAILINGROBOTS_HOME)/tests/testsuite/testRudderCommand.cpp -fprofile-arcs -ftest-coverage $(LIBS) -o metatest 


clean :
	rm -f $(FILE)
	rm -f example
	rm -f metatest
	rm -f *.gcda
	rm -f *.gcno


metalog :
	make metatest
	./metatest
	gcov -r RudderCommand.cpp
	grep -wE "(#####)" RudderCommand.cpp.gcov >> metatestlog.txt	
	sed -i '1s/^/Codelines below not tested by test*.cpp\n/' metatestlog.txt
	gcov -r RudderCommand.cpp >> metatestlog.txt
	make clean
