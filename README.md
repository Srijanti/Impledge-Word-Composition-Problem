# Impledge-Word-Composition-Problem

# Overview
This program is designed to find the longest and second longest compounded words from a list of words using a trie data structure. The solution includes a C++ implementation that reads words from input files, processes them using the trie, and outputs the results.

# Design
Trie Implementation
The program uses a trie data structure to efficiently store and retrieve words. The TrieNode structure represents a node in the trie, and the Solution class manages the trie operations such as insertion, search, and flag manipulation.

# Word Processing
The Solution class includes methods for inserting words into the trie, searching for compounded words, and marking/unmarking the end of words. The program utilizes recursion to navigate the trie during searches and updates.

# Decision
We opted for a trie data structure to efficiently store and process a large number of words.
Recursion simplifies code structure and allows seamless traversal of the trie, enhancing readability and maintainability.
Words are sorted based on length in descending order.

# File Input/Output
The program reads words from input files specified in the filenames vector. Each input file is processed independently, and the results are printed to the console.

# How to Execute

1. Clone the Repository and open it on any IDE platform.
2. Go to solution file
3. Compile and Run
4. View Results:

The program will output the longest and second-longest compounded words for each input file along with the time taken for processing.

# Example Input Files
Input_01.txt, 
Input_02.txt

# Notes
The program unmarks the flag of a word before searching for compounded words to prevent bias towards longer words.
Sorting is performed to prioritize longer words during the search.

# Performance
The program's performance can be measured by the time taken to process each input file. The duration is calculated using the C++ <chrono> library.
