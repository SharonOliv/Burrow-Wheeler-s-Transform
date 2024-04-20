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
Overall ,It takes O(n*logn) time.

# REAL-LIFE APPLICATIONS
<h3>1.Data Compression:</h3>
BWT is often used as a preprocessing step in data compression algorithms like the Burrows-Wheeler Compression (BWC) and the popular Bzip2. It rearranges the data in a way that makes it more amenable to compression, particularly for repetitive data.

<h3>2.Bioinformatics:</h3> 
    In genomics and bioinformatics, BWT is used in DNA sequence alignment algorithms such as Bowtie and BWA (Burrows-Wheeler Aligner). It efficiently aligns short DNA sequences to a reference genome, enabling tasks like DNA sequencing and analysis.

<h3>3.Data Encryption:</h3> 
    BWT can be employed in cryptographic applications. While not a standalone encryption method, it can be part of a larger encryption scheme, adding an extra layer of randomness to the data.

<h3>4.Data Search and Indexing:</h3>
BWT can facilitate fast text searching and indexing. Techniques like FM-index (based on BWT) are utilized in search engines, bioinformatics databases, and data retrieval systems, allowing for rapid substring searches even in large datasets.

<h3>5.Data Transmission:</h3>
BWT can be used in data transmission and error correction mechanisms. By transforming the data into a more compressible form, it can reduce the amount of data that needs to be transmitted, thereby saving bandwidth and speeding up communication.

<h3>6.Image and Signal Processing:</h3>
BWT has applications in image and signal processing for tasks like image compression and watermarking. By exploiting redundancy in image or signal data, BWT can efficiently represent them in a more compact form.

<h3>7.Blockchain and Cryptocurrencies:</h3>
In blockchain technology, BWT can be utilized for various purposes such as compressing transaction data before adding it to blocks, improving storage efficiency, and optimizing block propagation across the network.
