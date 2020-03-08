OBJECTS = main.o
CC = g++
CFLAGS = -c -g -Wall
INCLUDES =  -I/usr/include/libxml2
LIBS = /usr/lib64/libxml2.so.2.9.7

all: $(OBJECTS)
	$(CC) -o runxml $(OBJECTS) $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) main.cpp

.PHONY: clean
clean:
	rm -fr runxml ${OBJECTS}
	@echo "clean done"