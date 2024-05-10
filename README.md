# Genetic-Algorithm
Implementations of Genetic Algorithms in Artificial Intelligence for efficient optimization and problem-solving tasks.

# Question:

## Write a program to find a solution to the **Graph Coloring Problem**!
Explanation of Graph Coloring Problem:
- The input to this problem is an Undirected, Unweighted Graph
- The goal to be achieved in this problem is to give "color" to all vertices in the graph, with the following conditions:
 - Each pair of adjacent vertices is not colored with the same color
 - The total number of colors used is as little as possible
- Reference: https://en.wikipedia.org/wiki/Graph_coloring

## Program input:
- The input the program receives is a text file
- The contents of the input text file are **Adjacency List** with the following details:
 - The first row contains 2 numbers **V** and **E**, where **V** is the number of vertices in the graph and **E** is the number of edges in the graph
 - **E** the next row each contains 2 numbers **vx** and **vy**, where each row represents an edge between vertex **vx** and vertex **vy**
 - **vx** and **vy** (vertex names) are in the range between 0 to **V** - 1
- Example of input text file:
![Input](https://github.com/ezrabrilliant/Genetic-Algorithm/blob/main/image/example_input.png)

## Program output:
- The output of the program is in the form of a text file
- The contents of the output text file are as follows:
 - The first row contains 1 number **X**, namely the number of colors used to color the input graph
 - The second row contains **V** numbers **v0 v1 ... vV-1**, where a number **vi** represents the color used to color the **i**th vertex
 - **vi** (color) is in the range between 0 to **X** - 1
- Example of output text file (from the input above):
![Input](https://github.com/ezrabrilliant/Genetic-Algorithm/blob/main/image/example_output.png)

## It means:
- Number of colors used: 2
- Vertices 0, 2, and 3 are colored with the color "0"
- Vertex 1 is colored with the color “1”
- Output text file name: “out_” + [input text file name]
For example, for the input file "gc_4_1", the output file is named "out_gc_4_1"

## Description of the program created:
- Programming language: Free **(our group uses C++)**
- Recommended method: **Genetic Algorithm, Local Search**
