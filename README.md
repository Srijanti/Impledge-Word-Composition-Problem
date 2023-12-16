# Impledge-Word-Composition-Problem

# Overview
This program is designed to find the longest and second longest compounded words from a list of words using a trie data structure. The solution includes a C++ implementation that reads words from input files, processes them using the trie, and outputs the results.

# Design Decisions
Trie Implementation
The program uses a trie data structure to efficiently store and retrieve words. The TrieNode structure represents a node in the trie, and the Solution class manages the trie operations such as insertion, search, and flag manipulation.
The decision to use a Trie structure helps organize words effectively. Sorting words by length makes it easier to find longer compounded words. The Trie quickly checks if a word can be made using other words. The code is flexible, handling multiple input files, and uses C++11 for improved functionality.

# Approach
This code utilizes a Trie data structure to efficiently identify the longest and second-longest compounded words from a list. By sorting the words in descending order of length, it prioritizes longer words during the search process. The Trie is built by inserting each word, and during traversal, the code checks if a word can be formed using two or more other words. The resulting longest and second-longest compounded words are then displayed. The program is designed to process multiple input files, measuring the time taken for each operation. 

# How to Execute

1. Clone the Repository and open it on any IDE platform.
2. Go to solution file
3. Compile and Run
4. View Results:

# File Input/Output
The program reads words from input files specified in the filenames vector. Each input file is processed independently, and the results are printed to the console.

# Example Input Files
Input_01.txt, 
Input_02.txt

# Notes
The program unmarks the flag of a word before searching for compounded words to prevent bias towards longer words.
Sorting is performed to prioritize longer words during the search.

# Performance
The program's performance can be measured by the time taken to process each input file. The duration is calculated using the C++ <chrono> library.
