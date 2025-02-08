File Compression Project using Huffman Encoding
This is my File Compression project where I’ve implemented a Huffman Encoding Algorithm to compress and decompress files in C++. The goal was to take a file (like a text file), compress it to a smaller size using a lossless compression technique, and then decompress it back to its original form when needed.

Features:
Compress Files: The program reads a file, figures out how often each character shows up, and uses that information to build a Huffman tree. The characters are then compressed and saved as a .zip file.

Decompress Files: If you have a compressed file, the program can decode it using the Huffman tree, restoring the original text.

Progress Bar Animation: As the program reads, encodes, or decodes the file, there’s a fun progress bar to keep you updated on how things are going. I added it just to make the process feel a little smoother.

Metadata: After compression, the program saves some metadata about the file size and encoding in a separate text file. This way, you can track how efficient the compression was.

Files in the Project:
READFILE.cpp: This part handles reading the input file and displaying a progress bar animation while doing so. It also processes the contents of the file.

LINKEDLIST.cpp: Implements a linked list to store character frequencies and manage the nodes of the Huffman tree.

TREE.cpp: This is where the magic of the Huffman tree happens! It builds the tree based on the frequencies of characters and handles encoding and decoding the data.

MAIN.cpp: This is the main file where everything comes together. It takes care of user inputs and makes sure the right operations (compression and decompression) happen.

How It Works:

Reading the File:
First, you’re prompted to enter the name of the file you want to compress.
The program reads the file, and for each character, it tracks how often it appears.

Building the Huffman Tree:
Based on those frequencies, the program creates a Huffman tree. Each character gets a unique binary code, and the tree helps figure out the most efficient encoding.

File Encoding:
Using the Huffman codes, the program then encodes the file and saves the compressed version as a .zip file.

File Decoding:
If you want to restore the original file, the program can decode the compressed file back to its original text using the Huffman tree.

How to Use:
To Compress a File:
Just run the program, type in the file name you want to compress, and the program will create a new .zip file with the compressed data.

To Decompress a File:
If you have a .zip file that you want to decompress, you can run the program, and it’ll recreate the original .txt file from the compressed version.

Requirements:
C++ Compiler (like GCC or MSVC)
Standard C++ libraries (no external dependencies)



