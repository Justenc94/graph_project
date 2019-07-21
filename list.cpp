/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "list.h"

List::List() {
    head = nullptr;
    count = 0;
}

List::~List(){
    clear();
}

//********************************************PUBLIC METHODS********************************************
bool List::addNode(int new_id, string new_data) {
    Node *temp_node = head;
    if (searchIds(new_id) == -1) {
        Node *new_node = new Node;
        new_node->id = new_id;
        new_node->data = new_data;
        if (temp_node == nullptr || temp_node->id > new_id) {
            addHead(new_node);
            return true;
        } else {
            for (int i = 0; i < count; i++) {
                while(temp_node->next == nullptr){
                    addTail(new_node);
                    return true;
                }
                while(new_id > temp_node->id && new_id < temp_node->next->id){
                    addMiddle(new_node);
                    return true;
                }
                temp_node = temp_node->next;
            }
        }
    }
    return false;
}

bool List::deleteNode(int del_id){
    int search = searchIds(del_id);
    if(del_id == head->id){
        deleteHead();
        return true;
    }else if(search == count){
        deleteTail(search);
        return true;
    }else if(search != -1){
        deleteMiddle(search);
        return true;
    }else{
        return false;
    }
}

bool List::getNode(int id_search, DataNode *temp_data_node){
    Node *temp_node = head;
    int search = searchIds(id_search);
    for (int i = 0; i < search; i++) {
        if(id_search == temp_node->id){
            temp_data_node->id = temp_node->id;
            temp_data_node->data = temp_node->data;
            return true;
        }
        temp_node = temp_node->next;
    }
    return false;
}

void List::printList(bool direction){
    Node *temp_node;
    temp_node = head;
    if(direction) {
        if (count == 0) {
            cout << "=======================================" << endl;
            cout << "\t    LIST IS EMPTY" << endl;
            cout << "=======================================" << endl << endl;
        } else {
            cout << "================ Printing List ================" << endl;
            for (int i = 0; i < count; i++) {
                cout << "ID: " << temp_node->id << "\tDATA: " << temp_node->data << "\tNode Number: " << (i + 1)
                     << endl;
                temp_node = temp_node->next;
            }
            cout << "===============================================" << endl << endl;
        }
    }else{
        for (int j = 0; j < count-1; j++) {
            temp_node = temp_node->next;
        }
        cout << "================ Printing List ================" << endl;
        for (int i = count; i > 0; i--) {
            cout << "ID: " << temp_node->id << "\tDATA: " << temp_node->data << "\tNode Number: " << (i + 1)
                 << endl;
            temp_node = temp_node->back;
        }
        cout << "===============================================" << endl << endl;
    }
}

int List::getCount(){
    return count;
}

bool List::clear(){
    Node *temp_node = head;
    Node *del_node;
    if(count != 0){
        for (int i = 0; i < count; i++) {
            del_node = temp_node->next;
            delete temp_node;
            temp_node = del_node;
        }
        count = 0;
        head = nullptr;
        return true;
    }else{
        return false;
    }
}

//********************************************HELPER METHODS********************************************

//method to determine if an id is already in list and if not - return position where node should be added
int List::searchIds(int id_search){
    Node *temp_node = head;
    for (int i = 0; i < count; i++) {
        if(count == 0){
            return -1;
        }
        else if(temp_node->next != nullptr && id_search == temp_node->id){
            return (i+1);
        }
        else if((temp_node->next == nullptr && count != 0) && id_search == temp_node->id){
            return (i+1);
        }
        temp_node = temp_node->next;
    }
    return -1;
}

int List::getNodePos(int id_search){
    Node *temp_node = head;
    for (int i = 0; i < count; i++) {
        if(temp_node->id < id_search && temp_node->next->id > id_search){
            return i+1;
        }else{
            temp_node = temp_node->next;
        }
    }
    return -1;
}

void List::addHead(Node *new_node){
    Node *temp_node = head;
    if(temp_node == nullptr){
        head = new_node;
        new_node->next = nullptr;
        new_node->back = nullptr;
        count++;
    }else{
        new_node->next = temp_node;
        new_node->back = nullptr;
        temp_node->back = new_node;
        head = new_node;
        count++;
    }
}

void List::deleteHead(){
    Node *temp_node = head;
    head = temp_node->next;
    delete temp_node;
    count--;
    if(count == 0){
        head = nullptr;
    }
}

void List::addMiddle(Node *new_node){
    Node *temp_node = head;
    int node_pos = getNodePos(new_node->id);
    for (int i = 0; i < node_pos; i++) {
        temp_node = temp_node->next;
    }
    new_node->next = temp_node;
    new_node->back = temp_node->back;
    temp_node->back->next = new_node;
    temp_node->back = new_node;
    count++;
}

void List::deleteMiddle(int del_pos){
    Node *temp_node = head;
    for (int i = 0; i < del_pos-1; i++) {
        temp_node = temp_node->next;
    }
    temp_node->back->next = temp_node->next;
    temp_node->next->back = temp_node->back;
    delete temp_node;
    count--;
}

void List::addTail(Node *new_node){
    Node *temp_node = head;
    for (int i = 0; i < count; ++i) {
        if(temp_node->id < new_node->id){
            if(temp_node->id > new_node->id || temp_node->next == nullptr){
                temp_node->next = new_node;
                new_node->next = nullptr;
                new_node->back = temp_node;
                count++;
            }else{
                temp_node = temp_node->next;
            }
        }
    }
}

void List::deleteTail(int del_pos){
    Node *temp_node = head;
    for (int i = 0; i < count-1; i++) {
        temp_node = temp_node->next;
    }
    temp_node->back->next = nullptr;
    delete temp_node;
    count--;
}
