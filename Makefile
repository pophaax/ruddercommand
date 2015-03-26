#######################################################
#
#    Aland Sailing Robot
#    ===========================================
#    ruddercommand
#    -------------------------------------------
#
#######################################################

CC = g++
FLAGS = -Wall -pedantic -Werror
LIBS =

SOURCES = RudderCommand.cpp
HEADERS = RudderCommand.h
FILE = RudderCommand.o



all : $(FILE)
$(FILE) : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -c -o $(FILE)

example : $(SOURCES) $(HEADERS) example.cpp
	$(CC) $(SOURCES) example.cpp $(FLAGS) $(LIBS) -o example

clean :
	rm -f $(FILE)
	rm -f example


# Make for test
CC = g++
FLAGS = 
LIBS =

SOURCES = RudderCommand.cpp
SOURCE_TEST = testRudderCommand.cpp
HEADERS = RudderCommand.h 
HEADER_CATCH = catch.hpp

test : $(SOURCES) $(HEADERS) $(HEADER_CATCH) $(SOURCE_TEST)
	$(CC) $(SOURCES) $(SOURCE_TEST) $(FLAGS) $(LIBS) -o test


clean :
	rm -f test
