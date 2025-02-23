#!/bin/bash
if [ -z "$1" ]; then
	echo "parameter is not given"
	exit 1
fi

# Navigate to the specified directory
cd "$1" || { echo "Directory not found"; exit 1; }

> code_compressed.txt

# Copy .c files with their names
for file in *.c; do
	echo "File: $file" >> code_compressed.txt
	cat "$file" >> code_compressed.txt
done

# Check if the "inc" directory exists before changing to it
if [ -d "inc" ]; then
	cd "inc" || { echo "Failed to enter inc directory"; exit 1; }
	
	# Copy .h files with their names
	for file in *.h; do
		echo "File: $file" >> ../code_compressed.txt
		cat "$file" >> ../code_compressed.txt
	done
else
	echo "inc directory does not exist"
fi
