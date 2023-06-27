# Project Name

## Objective

The goal of this project is to compare the performance of the `map` and `unordered_map` data structures in C++ by measuring the time taken to insert and delete a fixed number of elements. The project aims to provide insights and analysis on the performance differences between these two data structures.

## Description

Hash maps are widely used data structures for efficient storage and retrieval of data in constant time. In C++, the `map` and `unordered_map` are two commonly used hash map data structures. The main difference between them lies in the underlying implementation and the behavior regarding element ordering.

The `map` data structure is implemented as a red-black tree and stores elements in a sorted order based on the keys. Inserting and deleting an element in a `map` has a time complexity of O(log n), making it suitable for use cases where elements need to be accessed in a specific order.

On the other hand, the `unordered_map` data structure uses a hash table to store elements and does not guarantee any specific order. Inserting and deleting an element in an `unordered_map` has an average time complexity of O(1), making it more efficient for cases that require fast insertions and deletions.

For this project, you will compare the performance of these two data structures by measuring the time taken to insert and delete a fixed number of elements (names represented as strings) in both the `map` and `unordered_map`. To ensure a fair comparison, you will implement your own hash function and use chaining to handle collisions. Both data structures will use the same hash function.

## Redirected Input File

To provide the necessary commands for the program, you will use a redirected input file. The file will contain a list of commands in the following format:

        I Erin
        I Adam
        I Elsa
        R Adam
        R Erin
        ...


The commands include inserting names (strings) and removing names from the data structure. It can be assumed that the names to be removed already exist in the data structure. You will open the file once to read the commands and create the data structure using the `map`. After closing the file, you will open it again to build the data structure using the `unordered_map`.

## Redirected Input

To use redirected input in the Visual Studio environment (on Windows), follow these steps:

1. After opening or creating a new project, go to **Project** > **Project Properties**.
2. Expand **Configuration Properties** until you see **Debugging**.
3. On the right side, you will find a set of options. In the **Command Arguments** field, type `< "input filename"`, where `<` denotes redirected input and "input filename" is the name of the input file (including the path if not in the working directory).

If you are using macOS, Linux, or Windows with PowerShell, you may compile and run the program using `g++`. Ensure that the program and the input file are in the same folder. Here are the commands:

        ```shell
        # Compile the program
        g++ project6.cpp -o p6
        
        # Run the program with redirected input
        ./p6 < input1.txt
        '''

## Report and Timing

The time taken to create both the map and unordered_map data structures were measured. Multiple input files of different lengths were used to test the structures, including worst and best cases for insertion. 

To measure the time, use the following code snippets as a reference:

        '''c++
        // Start timer
        clock_t start1 = clock
        '''
