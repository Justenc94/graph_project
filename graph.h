/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>
#include <iostream>
#include <string>
#include "main.h"
#include "data.h"

class Graph {

public:

    Graph();
    //TODO: Breadth-First traversal method - outputs to console
    //TODO: Depth-First traversal method - outputs to console
    //TODO: *BONUS* Point to Point traversal method - outputs to console
    //TODO: Method to output adjacency matrix to a new data file
    //TODO: Graph manipulation: Add a vertex
    //TODO: Graph manipulation: Remove a vertex
    //TODO: Graph manipulation: Add an edge
    //TODO: Graph manipulation: Remove an edge
    //TODO: Graph information: Get number of vertices
    //TODO: Graph information: Get number of edges
    //TODO: Graph information: Is connected: true or false
    //TODO: Graph information: List disconnected: Lists vertices that aren't connected

    void makeGraph(std::string);

    void addVertex(char, char);
    void addEdge(int, int);

private:
    //TODO: Helper methods or above methods that need to access private data
    //TODO: Will probably have to have helper methods for the cases: undirected weighted, directed unweighted
    void makeDirectedGraph();

};

#endif //GRAPH_H
