
all: cache-access.c
	gcc cache-access.c -o cache-access

clean:
	rm cache-access
