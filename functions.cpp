/***********************************************************
Name: Justen Crockett
Assignment: 06 - FINAL PROJECT
Purpose:
Notes:
***********************************************************/

#include "functions.h"

int get_filesize(string file_name){
    ifstream data_file;
    data_file.open(file_name);

    int size = 0;
    string data_string;

    //sets the size of the data to how many lines there are in the csv file passed to function
    while (getline(data_file, data_string, '\n')){
        if(!data_string.empty()){                //accounts for empty lines after data and doesn't add those to the size
            ++size;
        }
    }


    data_file.close();
    return size;
}

int check_file(int arg_count, char **file_name){
    fstream temp_file;
    if(arg_count < 1){
        return -1;
    }else{
        for (int i = 0; i < arg_count; i++) {
            temp_file.open(file_name[i]);
            if(temp_file.good()){
                return i;
            }
        }
        return -1;
    }
}
