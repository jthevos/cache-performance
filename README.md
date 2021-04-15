# cache-performance

1.  How big is a cache block?

    For this experiment, we created an array of the same size from experiment 2 where we found the cache size.
    We then populated this array then accessed increasing numbers of bytes multiple times.

2.  How big is the cache?


    The cache is around 261Kb as determined by experimental trial. The time taken accessing values
    above this threshold goes up noticeably at this size.

3.  How long does a reference to main memory take to complete?


    We accessed a very large array 1 million times with random access indices.

    ```
    mean      262.108155 ms / 1000000 accesses
    median    151.941500 ms / 1000000 accesses
    n = 200
    ```

4.  How long does a reference that can be satisfied from cache take to complete?


    We accessed an array we knew would fit into cache 1 million times

    ```
    mean      17.941965 ms / 1000000 accesses
    median    17.306500 ms / 1000000 accesses
    n = 200
    ```
