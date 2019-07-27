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
#include <vector>
#include "main.h"
#include "data.h"

class Graph {

public:

    Graph();
    ~Graph();
    //TODO: Breadth-First traversal method - outputs to console
    //TODO: Depth-First traversal method - outputs to console
    //TODO: *BONUS* Point to Point traversal method - outputs to console
    //TODO: Method to output adjacency matrix to a new data file
    //TODO: Graph manipulation: Remove a vertex
    //TODO: Graph manipulation: Remove an edge
    //TODO: Graph information: Is connected: true or false
    //TODO: Graph information: List disconnected: Lists vertices that aren't connected

    void print_graph();
    void addEdge(char, char);
    void addEdge(char, char, int);

    void traverseBFS(char);
    void traverseDFS(char);

    int vertexCount();
    int edgeCount();

    void addVertex(char);



private:
    //TODO: Helper methods or above methods that need to access private data
    //TODO: Will probably have to have helper methods for the cases: undirected weighted, directed unweighted

    bool addEdgeUndirected(char, char, int, vector<Node*>);
    bool addEdgeDirected(char, char, vector<Node*>);

    void traverseBFS(char, vector<Node*>);
    void traverseDFS(char, vector<Node*>);

    int edge_count;
    int vertex_count;

    vector<Node *> graph_nodes;

};

#endif //GRAPH_H
