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

    graph.makeGraph(argv[file_position]);

    graph.printGraph();

    return 0;
}