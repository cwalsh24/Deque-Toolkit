# Connor Walsh, Isaac Copeland, Kyle Byassee (Code4Days)
# Makefile for the deque assignment
# Date: 11/21/2022
# The purpose of this file is to compile the deque code
# and create a deque executable.

# Compile using the g++ compiler
CC = g++
# Compile with all errors and warnings
CFLAGS = -Wall -Wextra -g -c
# Target variable
TARGET = -Wall -Wextra -g -o deque

# default target
default: deque

# compilation instructions for the deque executable
deque: deque.o driver.o
	$(CC) $(TARGET) deque.o driver.o

# compilation instructions for the deque object files
deque.o: deque.cpp deque.h
	$(CC) $(CFLAGS) deque.cpp

driver.o: driver.cpp deque.h
	$(CC) $(CFLAGS) driver.cpp

# make clean instructions
clean:
	$(RM) deque *~ *.o
