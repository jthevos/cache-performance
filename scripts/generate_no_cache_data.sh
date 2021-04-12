#!/usr/bin/env bash
make

for i in `seq 1 200`; do
    ./no_cache_access >> data/no_cache/no_cache_1.csv
done
