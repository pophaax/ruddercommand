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

test : $(SOURCES) $(HEADERS) ../catch.hpp testRudderCommand.cpp
	$(CC) $(SOURCES) testRudderCommand.cpp $(LIBS) -o test

metatest : $(SOURCES) $(HEADERS) ../catch.hpp testRudderCommand.cpp
	$(CC) $(SOURCES) testRudderCommand.cpp -fprofile-arcs -ftest-coverage $(LIBS) -o metatest 


clean :
	rm -f $(FILES)
	rm -f example
	rm -f test
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
