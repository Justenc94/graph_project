/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "main.h"

int main(int argc, char** argv) {

    //checks files name passed from terminal
    int file_position = check_file(argc, argv);

    //exits program if what is passed from terminal is not a file
    if(file_position == -1){
        cout << "ERROR: Please re-run program and enter a valid file name." << endl;
        return 0;
    }else{
        cout << "File is a valid file." << endl;
    }

    //get file size
    int file_size = get_filesize(argv[file_position]);

    //exits program if what is passed from terminal is an empty data file
    if (file_size == 0){
        cout << "ERROR: File has no data inside it, please re-run program with a non empty file." << endl;
        return 0;
    }else{
        cout << "File is NOT empty" << endl;
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

    //data_file.seekg(0);
    getline(data_file, data_string, '\n');
    stringstream ss(data_string);
    while(getline(ss, data_string, ',')){
        labels[i] = data_string;
        i++;
    }


    for (int i = 0; i < file_size-1; ++i) {
        getline(data_file, data_string, ',');

        for (int j = 0; j < file_size-1; ++j) {
            getline(data_file, data_string, ',');
            istringstream buffer(data_string);
            buffer >> adj_matrix[i][j];
        }
    }

//    for (int i = 0; i < file_size-1; ++i) {
//        for (int j = 0; j < file_size-1; ++j) {
//            cout << adj_matrix[i][j] << " ";
//        }
//        cout << endl;
//    }

    cout << "Adding all nodes in data file to the graph..." << endl;
    for (int i = 0; i < file_size-1; i++) {
        cout << labels[i] << " added to graph." << endl;
        graph.addVertex(*labels[i].c_str());
    }
    cout << "Vertex count: " << graph.vertexCount() << endl;
    if(graph.isConnected()){
        cout << "Graph is connected." << endl;
    }else{
        cout << "Graph is not connected." << endl;
    }

    if(graph.showDisconnected()){
        cout << "No disconnected nodes to display." << endl;
    }else{
        cout << "  <----- Disconnected nodes" << endl;
    }















//
//    graph.addVertex('a');
//    graph.addVertex('b');
//    graph.addVertex('c');
//    graph.addVertex('d');
//    graph.addVertex('e');
//    graph.addVertex('f');
////    graph.addVertex('g');
////    graph.addVertex('h');
////    graph.addVertex('i');
////    graph.addVertex('z');
//
//
//
////    graph.addEdge('a', 'b', 10);
////    graph.addEdge('a', 'c', 5);
////    graph.addEdge('a', 'd', 15);
////    graph.addEdge('b', 'e', 10);
////    graph.addEdge('e', 'f', 5);
////    graph.addEdge('f', 'g', 15);
////    graph.addEdge('g', 'h', 10);
////    graph.addEdge('e', 'i', 5);
////    graph.addEdge('c', 'z', 50);
////    graph.addEdge('c', 'f', 50);
////    graph.addEdge('z', 'f', 50);
//
//
//
//
//    graph.addEdge('a', 'b');
//    //graph.addEdge('a', 'c');
////    graph.addEdge('a', 'd');
////    graph.addEdge('e', 'b');
////    graph.addEdge('b', 'f');
////    graph.addEdge('e', 'g');
////    graph.addEdge('e', 'i');
////    graph.addEdge('f', 'g');
////    graph.addEdge('f', 'd');
//
//
//    graph.print_graph();
//
//    //graph.removeEdge('f', 'g');
//    //graph.removeVertex('z');
//
//
//    graph.traverseBFS('a');
//
//    graph.traverseDFS('a');
//
//
//    cout << "\n***********************" << endl;
//    cout << "Vertex count: " << graph.vertexCount() << endl;
//    cout << "Edge count: " << graph.edgeCount() << endl;
//
//    cout << "\n\n***** Testing is connected method *****" << endl;
//    if(graph.isConnected()){
//        cout << "CONNECTED" << endl;
//    }else{
//        cout << "NOT CONNECTED" << endl;
//    }
//
//    if(graph.showDisconnected()){
//        cout << "No disconnected nodes to display." << endl;
//    }else{
//        cout << "  <----- Disconnected nodes" << endl;
//    }
//
//
//

    return 0;
}