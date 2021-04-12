#!/usr/bin/env bash
make

for i in `seq 1 200`; do
    ./cache_access >> data/cache/cache_1.csv
done
