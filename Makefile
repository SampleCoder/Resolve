# Build resolve program.
CC = g++
CFLAGS = -Wall -O2

all: reslv

reslv: creslv.o
	$(CC) $(CFLAGS) reslv.cpp creslv.o -o reslv

creslv.o:
	$(CC) $(CFLAGS) -c creslv.cpp -o creslv.o

clean:
	rm -f reslv *.o
