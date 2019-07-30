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
#include<bits/stdc++.h>
#include "main.h"
#include "data.h"

class Graph {

public:

    Graph();
    ~Graph();
    //TODO: *BONUS* Point to Point traversal method - outputs to console
    //TODO: Method to output adjacency matrix to a new data file

    void print_graph();
    void addEdge(char, char);
    void addEdge(char, char, int);

    void removeEdge(char, char);
    void removeVertex(char);

    void traverseBFS(char);
    void traverseDFS(char);

    int vertexCount();
    int edgeCount();

    void addVertex(char);

    bool isConnected();
    bool showDisconnected();


private:

    void removeEdge(char, char, Node*);

    bool addEdgeUndirected(char, char, int, vector<Node*>);
    bool addEdgeDirected(char, char, vector<Node*>);

    void traverseBFS(char, Node*);
    void traverseDFS(char, Node*);

    int edge_count;
    int vertex_count;

    vector<Node *> graph_nodes;
    bool weighted;
};

#endif //GRAPH_H
