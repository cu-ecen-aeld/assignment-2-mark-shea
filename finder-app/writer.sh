#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required: <file path> <write string>"
    exit 1
fi

writefile="$1"
writestr="$2"

# Create the directory path if it doesn't exist
dirpath=$(dirname "$writefile")
mkdir -p "$dirpath"
if [ $? -ne 0 ]; then
    echo "Error: Could not create directory path '$dirpath'"
    exit 1
fi

# Write the string to the file (overwrite if exists)
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Could not write to file '$writefile'"
    exit 1
fi

exit 0