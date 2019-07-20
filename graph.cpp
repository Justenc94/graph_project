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
        makeDirectedGraph(file_name);
    }else{
        cout << "undirected" << endl;
        makeUndirectedGraph(file_name);
    }
}

void Graph::makeDirectedGraph(string file_name) {
    ifstream data_file;
    string data_string;

    data_file.open(file_name);
    while(!data_file.eof()){
        while (getline(data_file, data_string, '\n')){
            cout << "Data: " << data_string << endl;
        }
        while (getline(data_file, data_string, ',')){
            cout << "Data: " << data_string << endl;
        }
        while (getline(data_file, data_string, '\n')){
            cout << "Data: " << data_string << endl;
        }
    }
}

void Graph::makeUndirectedGraph(string file_name) {
    ifstream data_file;
    data_file.open(file_name);
}

void Graph::addVertex(char name, char source) {

}

void Graph::addEdge(int, int) {

}
