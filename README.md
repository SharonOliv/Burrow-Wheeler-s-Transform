# BURROWS-WHEELER TRANSFORM
This repository contains the burrow-wheelr's transform algorithm along with its implementation in c,c++,python.

# INTRODUCTION
The Burrows-Wheeler Transform (BWT) is named after its inventors, Michael Burrows and David Wheeler. It is a data transformation algorithm that restructures data in such a way that the transformed message is more compressible. This algorithm is generally used in conjunction with the Move-to-Front (MTF) algorithm, Run length encoding(RLE) and the Huffman coding. It is also called as block sorting algorithm.

# HOW IT WORKS
The BWT algorithm is simple to understand. First the algorithm takes a string as input and generates the cyclic rotations of that string. Then it sorts all the rotations lexicographically. Finally after sorting, the last character of each rotation is taken to form the transformed string. These characters are concatenated together in the order of the sorted rotations to form the Burrows-Wheeler Transform.

# What is use of this algorithm
This algorithm is used many fields. It is primarily used in data compression and bioinformatics. For example, in data compression the transformed string obtained after using Burrows-wheeler transform is compressed efficiently using Huffman coding or RLE , thus by making the compression more amendable. 

# Time complexity
This repository also contains the doc file which demonstrates the time complexity of this algorithm.
Overall , It takes O(n*logn) time.

# REAL-LIFE APPLICATIONS
<b>1.Data Compression:</b><br>
<&emsp> BWT is often used as a preprocessing step in data compression algorithms like the Burrows-Wheeler Compression (BWC) and the popular Bzip2. It rearranges the data in a way that makes it more amenable to compression, particularly for repetitive data.

<b>2.Bioinformatics:</b><br> 
    In genomics and bioinformatics, BWT is used in DNA sequence alignment algorithms such as Bowtie and BWA (Burrows-Wheeler Aligner). It efficiently aligns short DNA sequences to a reference genome, enabling tasks like DNA sequencing and analysis.

<b>3.Data Encryption:</b><br> 
    BWT can be employed in cryptographic applications. While not a standalone encryption method, it can be part of a larger encryption scheme, adding an extra layer of randomness to the data.
