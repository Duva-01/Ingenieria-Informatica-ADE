OBJS	= main.o prototipo.o
SOURCE	= main.cpp prototipo.cpp
HEADER	= prototipo.h
OUT	= ejercicio1
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

prototipo.o: prototipo.cpp
	$(CC) $(FLAGS) prototipo.cpp 


clean:
	rm -f $(OBJS) $(OUT)
