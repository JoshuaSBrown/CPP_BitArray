CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra -std=c++11

All : test_BitArray

test_BitArray : BitArray.o
	$(CC) $(CFLAGS) BitArray.o test_BitArray.cpp -o test_BitArray

BitArray.o :
	$(CC) $(CFLAGS) BitArray.cpp -c

clean:
	rm *.o test_BitArray vgcore*
