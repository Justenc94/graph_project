/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "graph.h"

Graph::Graph() {
    edge_count = 0;
    vertex_count = 0;
}

Graph::~Graph() {

}

void Graph::makeGraph(string file_name) {
    ifstream data_file;
    string data_string;
    string file_check = "X";

    data_file.open(file_name);
    getline(data_file, data_string, ',');
    if(data_string == file_check){
        cout << "directed" << endl;         //DEBUG ONLY - NEED TO DELETE LATER
        makeDirectedGraph(file_name);
    }else{
        cout << "undirected" << endl;       //DEBUG ONLY - NEED TO DELETE LATER
        makeUndirectedGraph(file_name);
    }
}

void Graph::makeDirectedGraph(string file_name) {
    ifstream data_file;
    string data_string;
    int graph_size = get_filesize(file_name);

    data_file.open(file_name);

    getline(data_file, data_string, ',');
    for (int i = 0; i < graph_size-1; i++) {
        getline(data_file, data_string, ',');
        Node temp_node;
        temp_node.id = data_string[0];
        graph_data.push_back(temp_node);
    }
    for (int j = 0; j < graph_size-1; ++j) {
        cout << "ID: " << graph_data.at(j).id << endl;
    }
}

void Graph::makeUndirectedGraph(string file_name) {
    ifstream data_file;
    string data_string;
    int file_size = get_filesize(file_name);

    data_file.open(file_name);
    while(!data_file.eof()){
        cout << "Printing graph for debug:" << endl;

        while (getline(data_file, data_string, ',')){
            cout << data_string << endl;
        }
        while (getline(data_file, data_string, '\n')){
            cout << data_string << endl;
        }
    }
}

void Graph::addVertex(char name) {

}

void Graph::addEdge() {

}

void Graph::printGraph()
{
    int N = vertex_count;

    for (int i = 0; i < N; i++)
    {
        // print current vertex number
        cout << i << " --> ";

        // print all neighboring vertices of vertex i
        for (int v : adjList[i])
            cout << v << " ";
        cout << endl;
    }
}
