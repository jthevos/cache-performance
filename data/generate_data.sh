#!/usr/bin/env bash

make

for i in `seq 1 200`; do
    ./no_cache_access >> data/array_access_no_cache.csv
done

# for i in `seq 1 200`; do
#     ./cache_access >> data/cache.csv
# done
