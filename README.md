# Burrows-Wheeler-Transform
This repository contains the burrow-wheelr's transform algorithm along with its implementation in c,c++,python.

# INTRODUCTION
The Burrows-Wheeler Transform (BWT) is a data transformation algorithm that restructures data in such a way that the transformed message is more compressible. This algorithm is generally used in conjunction with the Move-to-Front (MTF) algorithm, Run length encoding(RLE) and the Huffman coding.

# HOW IT WORKS
The BWT algorithm is simple to understand. First the algorithm takes a string as input and generates the cyclic rotations of that string. Then it sorts all the rotations lexicographically. Finally after sorting, the last character of each rotation is taken to form the transformed string. These characters are concatenated together in the order of the sorted rotations to form the Burrows-Wheeler Transform.

# What is use of this algorithm
This algorithm is used many fields. It is primarily used in data compression and bioinformatics.

# REAL-LIFE APPLICATIONS
1.File Compression
2 DNA Referencing
