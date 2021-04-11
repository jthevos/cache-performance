
all: no_cache_access.c
	gcc no_cache_access.c -o no_cache_access
	#gcc cache_access.c -o cache_access

clean:
	rm no_cache_access
	#rm cache_access
