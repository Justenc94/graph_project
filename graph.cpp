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

bool Graph::removeEdge(char source, char dest) {
    for(auto search_graph : graph_nodes){
        for(auto search_edge : search_graph->edge_list){
            if(search_edge->source->label == source && search_edge->dest->label == dest){
                removeEdge(source, dest, search_graph);
                return true;
            }
        }
    }
    return false;
}

void Graph::addVertex(char name) {
    auto *temp_node = new Node;
    temp_node->label = name;
    graph_nodes.push_back(temp_node);
    vertex_count++;
}

bool Graph::removeVertex(char remove_label) {
    int i = 0;
    bool flag = false;

    for(auto remove_node : graph_nodes){
        if(remove_node->label == remove_label){
            graph_nodes.erase(graph_nodes.begin()+i);
            vertex_count--;
            flag = true;
        }
        i++;
    }
    if(!flag){
        return flag;
    }
    for(auto remove_node : graph_nodes){
        for(auto remove_edges : remove_node->edge_list){
            if(remove_edges->dest->label == remove_label || remove_edges->source->label){
                removeEdge(remove_edges->source->label, remove_label);
            }
        }
    }
    return flag;
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
    cout << "\nBreadth-First Search: " << endl;
    for(auto temp_graph : graph_nodes){
        if(temp_graph->label == start){
            traverseBFS(start, temp_graph);
        }
    }
    cout << endl;
}

void Graph::traverseDFS(char start) {
    //set all nodes visited flag to false to allow for multiple traversals
    for(auto set_visits : graph_nodes){
        for(auto edges : set_visits->edge_list){
            edges->dest->visited = false;
            edges->source->visited = false;
        }
    }
    cout << "\nDepth-First Search: " << endl;
    for(auto temp_graph : graph_nodes){
        if(temp_graph->label == start){
            traverseDFS(start, temp_graph);
        }
    }
    cout << endl;
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
                temp_graph->source->visited = temp_graph->dest->visited = true;
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

void Graph::outputGraph() {
    ofstream output_graph("graph04.dat");

    if(weighted){
        for(auto temp_graph : graph_nodes){
            int i = 0;
            if(temp_graph->edge_list.empty()){
                while(i < vertex_count){
                    output_graph << 'x' << ',';
                    i++;
                }
            }
            for(auto temp_edge : temp_graph->edge_list){
                i = 0;
                if(temp_edge->weight == -9){
                    output_graph << 'x' << ',';
                    i++;
                }
                else if(i < vertex_count && temp_edge->weight != -0 && temp_edge->weight < 0){
                    output_graph << 'x' << ',';
                    i++;
                }
                else{
                    output_graph << temp_edge->weight << ',';
                    i++;
                }
            }
            if(i < vertex_count){
                output_graph << 'x' << ',';
                i++;
            }
            output_graph <<  '\n';
        }

    }else{
        queue<Node*>node_queue;
        Node *temp_node = *graph_nodes.begin();
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
                    temp_graph->source->visited = temp_graph->dest->visited = true;
                    node_queue.push(temp_graph->dest);
                }
            }
            int i,j = 0;

            for(auto temp_graph : graph_nodes){
                if(i == 0){
                    output_graph << temp_graph->label << ",";
                    i++;
                }
                    if(!temp_graph->visited){
                        cout << temp_graph->label << "  ";
                        output_graph << "1" << ",";
                        j++;
                    }else{
                        cout << temp_graph->label << "  ";
                        output_graph << "0" << ",";
                        j++;
                    }
            }
            output_graph << '\n';

            while(j < vertex_count){
                for (int k = 0; k < vertex_count; ++k) {
                    output_graph << "0" << ",";
                }
                j++;
            }
        }

    }
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
    bool flag = false;

    for(auto add_edge : graph) {

        if(add_edge->label == source){
            temp_edge->source = add_edge;
            //Edge *node_ptr = temp_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
        if(add_edge->label == dest){
            temp_edge->dest = add_edge;
            flag = true;
            edge_count++;
            //add_edge->edge_list.push_back(temp_edge);
        }
    }
    return flag;
}

bool Graph::addEdgeDirected(char source, char dest, vector<Node*> graph) {

    Edge *temp_edge = new Edge;
    temp_edge->weight = -1;
    bool flag = false;

    for(auto add_edge : graph) {
        if(add_edge->label == source){
            temp_edge->source = add_edge;
            add_edge->edge_list.push_back(temp_edge);
        }
        if(add_edge->label == dest){
            temp_edge->dest = add_edge;
            flag = true;
            edge_count++;
        }
    }
    return flag;
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
    stack<Node*>node_stack;

    node_stack.push(temp_node);

    while(!node_stack.empty()){
        temp_node = node_stack.top();
        node_stack.pop();

        if(temp_node->visited){
            continue;
        }

        temp_node->visited = true;
        cout << temp_node->label << "  ";

        for(auto temp_edge : temp_node->edge_list){
            if(!temp_edge->dest->visited){
                node_stack.push(temp_edge->dest);
            }
        }
    }
}
