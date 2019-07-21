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

    data_file.open(file_name);
    while(!data_file.eof()){
        cout << "Printing graph for debug:" << endl;

        getline(data_file, data_string, '\n');

        while (getline(data_file, data_string, ',')){
            cout << data_string << endl;
        }
        while (getline(data_file, data_string, '\n')){
            cout << data_string << endl;
        }
    }
}

void Graph::makeUndirectedGraph(string file_name) {
    ifstream data_file;
    string data_string;
    int file_size = get_filesize(file_name);
    int adj_matrix[file_size][file_size];

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

void Graph::addVertex(char name, char source) {

}

void Graph::addEdge(int, int) {

}
