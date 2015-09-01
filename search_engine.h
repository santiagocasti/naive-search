#ifndef NAIVE_SEARCH_SEARCH_ENGINE_H
#define NAIVE_SEARCH_SEARCH_ENGINE_H


#include "btree_node.h"
#include "inverted_index.h"

using namespace std;

class search_engine {
    btree_node* prefix_tree;
    btree_node* suffix_tree;
    inverted_index* index;
    vector<pair<int, string>> *document_list;
    int last_document_id = 1;
public:
    search_engine();
    void index_document(string);
    list<int> find(string);
private:
    void index_line(string, int);
    void index_term(string, int);
    int add_document(string);
    bool has_indexed(string);
    int get_document_id(string);
};


#endif //NAIVE_SEARCH_SEARCH_ENGINE_H
