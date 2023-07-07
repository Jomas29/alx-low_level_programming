#!/bin/bash

# Collect all the .c files in the current directory
c_files=$(find . -maxdepth 1 -type f -name "*.c" -printf "%f\n")

# Compile each .c file and generate corresponding .o files
for file in $c_files; do
    gcc -c $file
done

# Create the static library liball.a from the generated .o files
ar rcs liball.a *.o
