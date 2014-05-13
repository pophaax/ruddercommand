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

