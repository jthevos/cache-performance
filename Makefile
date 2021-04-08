CC=gcc
CFLAGS=-c -Wall

all: security_guard

security_guard: security_guard.o binary_semaphore.o
	$(CC) security_guard.o binary_semaphore.o -o security_guard -lpthread

security_guard.o: security_guard.c binary_semaphore.h
	$(CC) $(CFLAGS) security_guard.c

binary_semaphore.o: binary_semaphore.c binary_semaphore.h
	$(CC) $(CFLAGS) binary_semaphore.c

clean:
	/bin/rm -f security_guard security_guard.o binary_semaphore.o
