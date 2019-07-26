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

//**********************************************   PUBLIC METHODS  **********************************************

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

void Graph::addEdge(char source, char dest) {
    addEdgeDirected(source, dest);
}

void Graph::addEdge(char source, char dest, int weight) {
    addEdgeUndirected(source, dest, weight, graph_nodes);
}



void Graph::addVertex(char name) {
    auto *temp_node = new Node;
    temp_node->label = name;
    graph_nodes.push_back(temp_node);
    vertex_count++;
}

int Graph::vertexCount() {
    return vertex_count;
}

int Graph::edgeCount() {
    return edge_count;
}

void Graph::print_graph() {

    cout << "Vertex count: " << vertex_count << endl;
    cout << "Edge count: " << edge_count << endl;

    int count = 0;

    for (auto print_node : graph_nodes) {
        cout << "\n======== Node ========" << endl;
        cout << "Label: " << print_node->label << endl;

        cout << "\n======== Edges ========" << endl;

        cout << "Num of edges: " << print_node->edge_list.size() << endl;

        for(auto print_edge : print_node->edge_list){
            cout << "-----------------------" << endl;
            cout << "Source: "  << print_edge->source->label << endl;
            cout << "Destination: " << print_edge->dest->label << endl;
            cout << "Weight: "  << print_edge->weight << endl;
        }
    }
}

//**********************************************   PRIVATE METHODS  **********************************************

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

bool Graph::addEdgeUndirected(char source, char dest, int weight, vector<Node*> graph) {

    Edge *temp_edge = new Edge;
    temp_edge->weight = weight;

    for(auto add_edge : graph) {
        if(add_edge->label == source){
            temp_edge->source = add_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
        if(add_edge->label == dest){
            temp_edge->dest = add_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
    }
    edge_count++;
    return true;
}

bool Graph::addEdgeDirected(char source, char dest) {
    edge_count++;
    return true;
}
