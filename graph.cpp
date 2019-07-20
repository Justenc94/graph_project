/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "graph.h"

Graph::Graph() {

}

void Graph::makeGraph(string file_name) {
    ifstream data_file;
    string data_string;
    string file_check = "X";

    data_file.open(file_name);
    getline(data_file, data_string, ',');
    if(data_string == file_check){
        cout << "directed" << endl;
        //TODO: call helper function to make directed graph
    }else{
        cout << "undirected" << endl;
        //TODO: call helper function to make undirected graph
    }
}

void Graph::makeDirectedGraph() {

}

void Graph::addVertex(char name, char source) {

}

void Graph::addEdge(int, int) {

}
