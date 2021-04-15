# cache-performance

1.  How big is a cache block?

2.  How big is the cache?
    The cache is around 261Kb as determined by experimental trial. The time taken accessing values
    above this threshold goes up noticeably at this size. 

3.  How long does a reference to main memory take to complete?
    We accessed a very large array 1 million times with random access indices.

    mean      262.108155 ms / 1000000 accesses
    median    151.941500 ms / 1000000 accesses
    n = 200

4.  How long does a reference that can be satisfied from cache take to complete?
    We accessed an array we knew would fit into cache 1 million times
    mean      17.941965 ms / 1000000 accesses
    median    17.306500 ms / 1000000 accesses
    n = 200

TODO:
1. Vary the array size. Our goal is to try to fit an array into the cache.
2. Accessing random elements of a 16k array should be fast because the whole thing is in cache.
    Contrast this with a 4MB array. This will not fit in the cache. Thus, we will see longer
    experimental times between accesses.
3. Keep number of accesses constant!!!
4. Testing blocksize comes down to accesses in a pattern, i.e., strides. We want to
    test different offsets (strides), to find the limit of each block.
5. There are some hints the compiler can give to the memory management unit to help,
    but the decisions made about cacheing are made at runtime.
