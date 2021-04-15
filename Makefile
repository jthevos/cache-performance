
all: cache_inquisitor.c cache_inquisitor1.c cache_inquisitor2.c cache_inquisitor3.c cache_inquisitor4.c no_cache_access.c
	gcc cache_inquisitor.c -o cache_inquisitor
	gcc cache_inquisitor1.c -o 1_cache_inquisitor
	gcc cache_inquisitor2.c -o 2_cache_inquisitor
	gcc cache_inquisitor3.c -o 3_cache_inquisitor
	gcc cache_inquisitor4.c -o 4_cache_inquisitor
	gcc no_cache_access.c -o no

clean:
	rm cache_inquisitor 1_cache_inquisitor 2_cache_inquisitor 3_cache_inquisitor 4_cache_inquisitor no
