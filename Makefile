# Build resolve program.
CC = g++
CFLAGS = -Wall -O2

all:
	$(CC) $(CFLAGS) reslv.cpp -o reslv

clean:
	rm -f reslv
