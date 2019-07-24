/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#ifndef DATA_H
#define DATA_H

#include <vector>
using namespace std;

struct Node;
struct Edge;

struct Node {
    char label;
    vector<Edge*> edge_list;
};

struct Edge {
    int weight;
    Node *source, *dest;
};

#endif //DATA_H
