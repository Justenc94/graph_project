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
    auto *temp_node = new Node;
    temp_node->label = name;
    graph_nodes.push_back(*temp_node);
    vertex_count++;
}

void Graph::addEdge(char source, char dest, int weight) {
    Edge *temp_edge = new Edge;

    temp_edge->weight = weight;

    int i = 0;

    for (auto &temp_source : graph_nodes) {
        cout << "Debug for add edge: " << temp_source.label << endl;
        if(source == temp_source.label){
            cout << "*** MATCH - SOURCE ***  - " << temp_source.label << endl;
            temp_source.edge_list.push_back(temp_edge);
        }
        i++;
    }
    for (auto &temp_dest : graph_nodes) {
        cout << "Debug for add edge: " << temp_dest.label << endl;
        if(dest == temp_dest.label){
            cout << "*** MATCH - DESTINATION ***  - " << temp_dest.label << endl;
            temp_dest.edge_list.push_back(temp_edge);
        }
    }
    edge_count++;
}

void Graph::print_graph() {

    cout << "Vertex count: " << vertex_count << endl;
    cout << "Edge count: " << edge_count << endl;

    for (auto print_node : graph_nodes) {
        cout << "\n======== Node ========" << endl;
        cout << "Label: " << print_node.label << endl;

        cout << "\n======== Edges ========" << endl;

        cout << "Num of edges: " << print_node.edge_list.size() << endl;
        cout << "Destination: " << endl;
        cout << "Weight: " << endl;
    }
}