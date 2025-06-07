#!/bin/bash

# This script run through filenames containing numbers from 1 to 10.
# chmod +x verify_results.sh
# ./verify_results.sh <folder_name>

# Check if the compiled program exists.
# g++ -std=c++17 -O2 -lm -o myprogram.out Bronze202012P3.cpp
if [ ! -f myprogram.out ]; then
  echo "myprogram.out not found. Please compile your program first."
  exit 1
fi  

# Check if an argument was provided.
# $# is a special variable that holds the count of arguments.
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <folder_name>"
    exit 1
fi

# The first command-line argument ($1) is used as the folder prefix.
# e.g. ~/Downloads/prob3_bronze_dec20
folder=$1
if [ ! -d "$folder" ]; then
  echo "Directory $folder does not exist. Please check the path."
  exit 1
fi

echo "Directory $folder exists. Running tests with myprogram.out..."
for i in {1..10}
do
  echo "  $i.in"
  cat $folder/$i.in | ./myprogram.out | diff -u - $folder/$i.out
done

echo "All tests completed."