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



void Graph::addEdge(char source, char dest) {
    addEdgeDirected(source, dest, graph_nodes);
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
            if(print_edge->weight != -1){
                cout << "Weight: "  << print_edge->weight << endl;
            }
        }
    }
}

//**********************************************   PRIVATE METHODS  **********************************************

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

bool Graph::addEdgeDirected(char source, char dest, vector<Node*> graph) {
    Edge *temp_edge = new Edge;
    temp_edge->weight = -1;

    for(auto add_edge : graph) {
        if(add_edge->label == source){
            temp_edge->source = add_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
        if(add_edge->label == dest){
            temp_edge->dest = add_edge;
        }
    }
    edge_count++;
    return true;
}
