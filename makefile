#use for ubuntu
OBJECTS = main.o
CC = g++
CFLAGS = -c -g -Wall
INCLUDES =  -I/usr/include/libxml2
LIBS = /usr/lib/x86_64-linux-gnu/libxml2.so.2.9.4

all: $(OBJECTS)
	$(CC) -o runxml $(OBJECTS) $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) main.cpp

.PHONY: clean
clean:
	rm -fr runxml ${OBJECTS}
	@echo "clean done"
