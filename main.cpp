/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "main.h"

int main(int argc, char** argv) {

//    //checks files name passed from terminal
//    int file_position = check_file(argc, argv);
//
//    //exits program if what is passed from terminal is not a file
//    if(file_position == -1){
//        cout << "ERROR: Please re-run program and enter a valid file name." << endl;
//        return 0;
//    }else{
//        cout << "File is a valid file." << endl;
//    }
//
//    //get file size
//    int file_size = get_filesize(argv[file_position]);
//
//    //exits program if what is passed from terminal is an empty data file
//    if (file_size == 0){
//        cout << "ERROR: File has no data inside it, please re-run program with a non empty file." << endl;
//        return 0;
//    }else{
//        cout << "File is NOT empty" << endl;
//    }
//
//
//    Graph graph;
//
//    graph.makeGraph(argv[file_position]);
//
//    auto *test_node_1 = new Node;
//    auto *test_node_2 = new Node;
//
//
//    test_node_1->label = 'a';
//    cout << "Testing 1... ID: " << test_node_1->label << endl;
//
//    test_node_2->label = 'b';
//    cout << "Testing 2... LABEL: " << test_node_2->label << endl;
//
//    auto *test_edge = new Edge;
//
//    test_edge->weight = 15;
//    test_edge->source = test_node_1;
//    test_edge->dest = test_node_2;
//
//    test_node_1->edge_list.push_back(*test_edge);
//
//    cout << "Testing... WEIGHT: " << test_node_1->edge_list.front().weight << endl;

    Graph graph;

    graph.addVertex('a');
    graph.addVertex('b');
    graph.addVertex('c');
    graph.addVertex('d');

    graph.addEdge('a', 'b', 10);
    graph.addEdge('a', 'c', 5);
    graph.addEdge('a', 'd', 15);

    graph.print_graph();

    return 0;
}