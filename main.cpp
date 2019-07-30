/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "main.h"

int main(int argc, char** argv) {

    srand(time(NULL));

    //checks files name passed from terminal
    int file_position = check_file(argc, argv);

    //exits program if what is passed from terminal is not a file
    if(file_position == -1){
        cout << "ERROR: Please re-run program and enter a valid file name." << endl;
        return 0;
    }

    //get file size
    int file_size = get_filesize(argv[file_position]);

    //exits program if what is passed from terminal is an empty data file
    if (file_size == 0){
        cout << "ERROR: File has no data inside it, please re-run program with a non empty file." << endl;
        return 0;
    }

    Graph graph;

    //true for directed - false for undirected
    bool directed_or_not;

    ifstream data_file;
    data_file.open(argv[file_position]);
    string data_string;
    string labels[file_size];
    int adj_matrix[file_size][file_size];
    int i = 0;

    getline(data_file, data_string, ',');

    if(data_string[0] == 'X'){
        cout << "DIRECTED GRAPH" << endl;
        directed_or_not = true;
    }else{
        cout << "UNDIRECTED GRAPH" << endl;
        directed_or_not = false;
    }

    //makes directed graph and tests methods
    if(directed_or_not){
        getline(data_file, data_string, '\n');
        stringstream ss(data_string);
        while(getline(ss, data_string, ',')){
            labels[i] = data_string;
            i++;
        }


        for (int i = 0; i < file_size-1; ++i) {
            if(i == 0){
                getline(data_file, data_string, ',');
            }
            for (int j = 0; j < file_size-1; ++j) {
                getline(data_file, data_string, ',');
                istringstream buffer(data_string);
                buffer >> adj_matrix[i][j];
            }
        }


        cout << "=======================================================" << endl;
        cout << "Adding all nodes in data file to the graph..." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < file_size-1; i++) {
            cout << labels[i] << " added to graph." << endl;
            graph.addVertex(*labels[i].c_str());
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }

        cout << "=======================================================" << endl;
        cout << "Adding all edges in data file to the graph..." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < file_size-1; i++) {
            for (int j = 0; j < file_size-1; ++j) {
                if(adj_matrix[i][j] == 1){
                    graph.addEdge(*labels[i].c_str(), *labels[j].c_str());
                    cout << "Edge added: " << labels[i] << " ---> " << labels[j] << endl;
                }
            }
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');

        int num_tests = random_range(2, 5);
        //labels to test add vertex - capitalized letters to distinguish from data file nodes
        char add_labels[6] ={
                'A', 'B', 'C', 'D', 'E', 'F'
        };


        cout << "=======================================================" << endl;
        cout << "Testing add vertex " << num_tests << " times." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < num_tests; ++i) {
            cout << add_labels[i] << " added to graph." << endl;
            graph.addVertex(add_labels[i]);
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');


        cout << "=======================================================" << endl;
        cout << "Testing add edge " << num_tests << " times." << endl;
        cout << "=======================================================" << endl;
        graph.addEdge(*labels[0].c_str(), add_labels[0]);
        cout << "Edge added: " << labels[0] << " ---> " << add_labels[0] << endl;
        for (int i = 0; i < num_tests-1; ++i) {
            int rand_source = random_range(0, 2);
            int rand_dest = random_range(0, 2);
            cout << "Edge added: " << add_labels[i] << " ---> " << add_labels[i+1] << endl;
            graph.addEdge(add_labels[i], add_labels[i+1]);
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');
    }

//--------------------------  makes undirected weighted graph and tests methods  ---------------------------------------

    else{
        cout << "undirected graph" << endl;

//        stringstream ss(data_string);
//        while(getline(ss, data_string, ',')){
//            labels[i] = data_string;
//            i++;
//        }

        char undirected_labels[16]  = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'
        };

        for (int i = 0; i < file_size; ++i) {
            labels[i] = undirected_labels[i];
            cout << "Label: " << labels[i] << endl;
        }




        for (int i = 0; i < file_size-1; ++i) {
            if(i == 0){
                getline(data_file, data_string, ',');
            }
            for (int j = 0; j < file_size-1; ++j) {
                getline(data_file, data_string, ',');
                istringstream buffer(data_string);
                buffer >> adj_matrix[i][j];
            }
        }

        cout << "=======================================================" << endl;
        cout << "Adding all nodes in data file to the graph..." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < file_size-1; i++) {
            cout << labels[i] << " added to graph." << endl;
            graph.addVertex(*labels[i].c_str());
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }

        cout << "=======================================================" << endl;
        cout << "Adding all edges in data file to the graph..." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < file_size-1; i++) {
            for (int j = 0; j < file_size-1; ++j) {
                if(adj_matrix[i][j] == 1){
                    graph.addEdge(*labels[i].c_str(), *labels[j].c_str());
                    cout << "Edge added: " << labels[i] << " ---> " << labels[j] << endl;
                }
            }
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');

        int num_tests = random_range(2, 5);
        //labels to test add vertex - capitalized letters to distinguish from data file nodes
        char add_labels[6] ={
                'A', 'B', 'C', 'D', 'E', 'F'
        };


        cout << "=======================================================" << endl;
        cout << "Testing add vertex " << num_tests << " times." << endl;
        cout << "=======================================================" << endl;
        for (int i = 0; i < num_tests; ++i) {
            cout << add_labels[i] << " added to graph." << endl;
            graph.addVertex(add_labels[i]);
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');


        cout << "=======================================================" << endl;
        cout << "Testing add edge " << num_tests << " times." << endl;
        cout << "=======================================================" << endl;
        graph.addEdge(*labels[0].c_str(), add_labels[0]);
        cout << "Edge added: " << labels[0] << " ---> " << add_labels[0] << endl;
        for (int i = 0; i < num_tests-1; ++i) {
            int rand_source = random_range(0, 2);
            int rand_dest = random_range(0, 2);
            cout << "Edge added: " << add_labels[i] << " ---> " << add_labels[i+1] << endl;
            graph.addEdge(add_labels[i], add_labels[i+1]);
        }
        cout << "*******************************************************" << endl;
        cout << "Vertex count: " << graph.vertexCount() << endl;
        cout << "Edge count: " << graph.edgeCount() << endl;
        if(graph.isConnected()){
            cout << "Graph is connected." << endl;
        }else{
            cout << "Graph is not connected." << endl;
        }
        if(graph.showDisconnected()){
            cout << "No disconnected nodes to display." << endl;
        }else{
            cout << "  <----- Disconnected node(s)" << endl;
        }
        cout << "-------------------------------------------------------" << endl;
        graph.traverseBFS('a');
        graph.traverseDFS('a');

    }

    return 0;
}