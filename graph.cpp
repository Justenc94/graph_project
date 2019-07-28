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

void Graph::traverseBFS(char start) {
    traverseBFS(start, graph_nodes);
}

void Graph::traverseDFS(char start) {
    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }
    cout << "******* DFS *******" << endl;
    traverseDFS(start, graph_nodes.front());
    cout << "\n*******************" << endl << endl;
}

int Graph::vertexCount() {
    return vertex_count;
}

int Graph::edgeCount() {
    return edge_count;
}

void Graph::print_graph() {

    int count = 0;

    for (auto print_node : graph_nodes) {
        cout << "\n======== Node ========" << endl;
        cout << "Label: " << print_node->label << endl;
        cout << "Visited: " << print_node->visited << endl;

        cout << "\n======== Edges ========" << endl;

        cout << "Num of edges: " << print_node->edge_list.size() << endl;

//        for(auto print_edge : print_node->edge_list){
//            cout << "-----------------------" << endl;
//            cout << "Source: "  << print_edge->source->label << endl;
//            cout << "Destination: " << print_edge->dest->label << endl;
//            if(print_edge->weight != -1){
//                cout << "Weight: "  << print_edge->weight << endl;
//            }
//        }
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

void Graph::traverseBFS(char start, vector<Node*> graph) {

    bool flag = false;

    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }

    cout << "\n\n******* BFS *******" << endl;
    for(auto search : graph){
        if(start == search->label){
            cout << "Start: " << search->label << endl;
            search->visited = true;
            flag = true;
        }

        for(auto edges : search->edge_list){
            if(!edges->dest->visited && flag){
                cout << edges->dest->label << "  ";
                edges->dest->visited = true;
            }
        }
    }
    cout << "\n*******************" << endl << endl << endl;
}

void Graph::traverseDFS(char start, Node *temp_node) {
    temp_node->visited = true;

    static bool flag = false;
    static int count = 0;

    if(!flag){
        for(auto search : graph_nodes){
            if(start == search->label){
                flag = true;
                traverseDFS(start, search);
            }
        }
    }

    if(count == 0){
        cout << "Start: " << temp_node->label << endl;
        count++;
    }


    for(auto temp_edge : temp_node->edge_list){
        if(!temp_edge->dest->visited){
            cout << temp_edge->dest->label << "  ";
            traverseDFS(start, temp_edge->dest);
        }else{
            return;
        }
    }
}
