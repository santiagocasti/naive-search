//
// Created by Santiago Castineira on 8/20/15.
//

#ifndef WILDCARDSEARCH_INVERTEDINDEX_H
#define WILDCARDSEARCH_INVERTEDINDEX_H

#include <string>
#include <list>
#include <unordered_map>

using namespace std;

class inverted_index {
    unordered_map<string, list<int>*> *index;
public:
    inverted_index();
    void add(string, int);
    list<int>* get_doc_ids(string);
};


#endif //WILDCARDSEARCH_INVERTEDINDEX_H
