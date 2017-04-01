CC = g++
DEBUG = -g
CFLAGS = -Wall -Wextra

test_BitArray : BitArray.o
	$(CC) $(CFLAGS) BitArray.o test_BitArray.cpp -o test_BitArray

BitArray.o :
	$(CC) $(CFLAGS) BitArray.cpp -c

clean:
	rm *.o
