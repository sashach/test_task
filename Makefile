
CC = g++

GTEST_DIR = /home/sasha/src/gtest

CFLAGS = -c -Wall -std=c++0x -I$(GTEST_DIR)/include/
LDFLAGS = $(GTEST_DIR)/lib/.libs/libgtest.a
LDADD = -pthread

SOURCES = main.cpp test_class.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = test

all: $(SOURCES) $(EXECUTABLE)
	./test
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDADD) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) 

