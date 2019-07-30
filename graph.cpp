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
    weighted = false;
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

void Graph::removeEdge(char source, char dest) {
    for(auto search_graph : graph_nodes){
        for(auto search_edge : search_graph->edge_list){
            if(search_edge->source->label == source && search_edge->dest->label == dest){
                removeEdge(source, dest, search_graph);
                edge_count--;
            }
        }
    }
}

void Graph::addVertex(char name) {
    auto *temp_node = new Node;
    temp_node->label = name;
    graph_nodes.push_back(temp_node);
    vertex_count++;
}

void Graph::removeVertex(char remove_label) {
    int i = 0;

    for(auto remove_node : graph_nodes){
        if(remove_node->label == remove_label){
            graph_nodes.erase(graph_nodes.begin()+i);
            vertex_count--;
        }
        i++;
    }
    for(auto remove_node : graph_nodes){
        for(auto remove_edges : remove_node->edge_list){
            if(remove_edges->dest->label == remove_label){
                removeEdge(remove_edges->source->label, remove_label);
            }
        }
    }
}

void Graph::traverseBFS(char start) {
    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            if(weighted){
                edges->source->visited = false;
            }
        }
    }
    cout << "\n*********** BFS ***********" << endl;
    for(auto temp_graph : graph_nodes){
        if(temp_graph->label == start){
            traverseBFS(start, temp_graph);
        }
    }
    cout << "\n***************************" << endl << endl;
}

void Graph::traverseDFS(char start) {
    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }
    cout << "*********** DFS ***********" << endl;
    for(auto temp_graph : graph_nodes){
        if(temp_graph->label == start){
            traverseDFS(start, temp_graph);
        }
    }
    cout << "\n***************************" << endl << endl;
}

int Graph::vertexCount() {
    return vertex_count;
}

int Graph::edgeCount() {
    return edge_count;
}

bool Graph::isConnected() {
    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }

    queue<Node*>node_queue;
    Node *temp_node = *graph_nodes.begin();

    node_queue.push(temp_node);

    while(!node_queue.empty()){
        temp_node = node_queue.front();
        node_queue.pop();
        temp_node->visited = true;

        for(auto temp_graph : temp_node->edge_list){
            if(!temp_graph->dest->visited){
                temp_graph->dest->visited = true;
                node_queue.push(temp_graph->dest);
            }
        }
    }
    for(auto temp_graph : graph_nodes){
        if(!temp_graph->visited){
            return false;
        }
    }
    return true;
}

bool Graph::showDisconnected() {
    queue<Node*>node_queue;
    Node *temp_node = *graph_nodes.begin();
    bool flag = true;
    temp_node->visited = false;

    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }

    node_queue.push(temp_node);

    while(!node_queue.empty()){
        temp_node = node_queue.front();
        node_queue.pop();

        for(auto temp_graph : temp_node->edge_list){
            if(!temp_graph->dest->visited){
                temp_graph->dest->visited = true;
                node_queue.push(temp_graph->dest);
            }
        }
    }
    for(auto temp_graph : graph_nodes){
        if(!temp_graph->visited){
            cout << temp_graph->label << "  ";
            flag = false;
        }
    }
    return flag;
}

void Graph::print_graph() {

    int count = 0;

    for (auto print_node : graph_nodes) {
        cout << "\n======== Node ========" << endl;
        cout << "Label: " << print_node->label << endl;
        cout << "Visited: " << print_node->visited << endl;

        cout << "\n======== Edges ========" << endl;

        cout << "Num of edges: " << print_node->edge_list.size() << endl;
    }
}

//**********************************************   PRIVATE METHODS  **********************************************

bool Graph::addEdgeUndirected(char source, char dest, int weight, vector<Node*> graph) {

    Edge *temp_edge = new Edge;
    temp_edge->weight = weight;
    weighted = true;

    for(auto add_edge : graph) {
        if(add_edge->label == source){
            temp_edge->source = add_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
        if(add_edge->label == dest){
            temp_edge->dest = add_edge;
            //add_edge->edge_list.push_back(temp_edge);
            //TODO: FIX THIS, NOT ADDING EDGE TO BOTH NODES
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

void Graph::removeEdge(char source, char dest, Node *node) {
    int i = 0;

    for(auto temp :  node->edge_list){
        if(temp->source->label == source && temp->dest->label == dest){
            node->edge_list.erase(node->edge_list.begin()+i);
            if(node->edge_list.size() > 2){
                temp->dest->edge_list.erase(temp->dest->edge_list.begin()+i);
            }
            edge_count--;
        }
        i++;
    }
}

void Graph::traverseBFS(char start, Node *temp_node) {

    queue<Node*>node_queue;

    node_queue.push(temp_node);

    while(!node_queue.empty()){
        temp_node = node_queue.front();
        node_queue.pop();
        cout << temp_node->label << "  ";
        temp_node->visited = true;

        for(auto temp_graph : temp_node->edge_list){
            if(!temp_graph->dest->visited){
                temp_graph->dest->visited = true;
                node_queue.push(temp_graph->dest);
            }
        }
    }
}


void Graph::traverseDFS(char start, Node *temp_node) {
    temp_node->visited = true;
    cout << temp_node->label << "  ";


    for(auto temp_edge : temp_node->edge_list){
        if(!temp_edge->dest->visited){
            traverseDFS(start, temp_edge->dest);
        }else{
            return;
        }
    }
}
