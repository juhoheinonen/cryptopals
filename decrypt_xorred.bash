#!/bin/bash

# Read line by line in file 4.txt
while IFS= read -r line; do
    ./set1_3 "$line"
done < 4.txt